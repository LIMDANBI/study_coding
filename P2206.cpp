#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;

int N, M, ans = 0;
char map[MAX][MAX];
int cnt[MAX][MAX][2];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

typedef struct Data{int y, x, chance;};

int bfs(){
    queue<Data> q;
    q.push({0,0,1}); // y, x, 뚫을 수 있는 기회
    cnt[0][0][1] = 1;

    while (!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int chance = q.front().chance;
        q.pop();

        if(y==N-1 && x==M-1) return cnt[y][x][chance]; // 도착한 경우 
        for(int i=0; i<4; i++){  // 상하좌우 탐색
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue; // 범위를 벗어나는 경우
            if(map[ny][nx]=='1' && chance){ // 벽이고, 벽을 뚫을 수 있는 찬스가 남은 경우 
                cnt[ny][nx][chance-1] = cnt[y][x][chance]+1;
                q.push({ny, nx, chance-1});
            }
            else if(map[ny][nx]=='0'){ // 갈 수 있고
                if(cnt[ny][nx][chance]!=0) continue; // 방문하지 않은 경우
                cnt[ny][nx][chance] = cnt[y][x][chance]+1;
                q.push({ny, nx, chance});
            }
        }

    }
    return -1; // 주어진 조건으로 (N, M)에 도착할 수 없는 경우
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    string str;
    for(int i=0; i<N; i++){ // 입력
        cin >> str;
        for(int j=0; j<M; j++) map[i][j] = str[j];
    }
    cout << bfs();
}