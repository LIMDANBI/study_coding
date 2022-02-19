#include<iostream>
#include<cstring>
#include<queue>
#define MAX 50
using namespace std;

int T, M, N, K;
int field[MAX][MAX];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

void dfs(int y, int x){
    field[y][x] = 0;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=M) continue; // 범위를 벗어난 경우 
        else if(field[ny][nx]==1) dfs(ny, nx); // 인근에 배추가 위치한 경우 방문
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--){
        int y, x, ans=0;
        queue<pair<int, int> > q; 

        memset(field, 0, sizeof(field)); // 초기화
        cin >> M >> N >> K;
        while(K--){
            cin >> x >> y;
            q.push({y, x}); // 배추 좌표 저장
            field[y][x] = 1; // y,x 위치에 배추 있음 표시
        }
        while (!q.empty()){
            int y = q.front().first;
            int x = q.front().second; 
            q.pop();
            if(field[y][x]==1) { // 이미 방문하지 않은 경우
                dfs(y, x); // 방문하고, 주변 탐색까지 진행!
                ans++;
            }
        }
        cout << ans << "\n"; 
    }
}