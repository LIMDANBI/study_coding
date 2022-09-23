#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;

int n, k, r, c;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void input(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> map[i][j];
    }
    cin >> r >> c;
}

int move(){
    int possible_max_num = -1;
    int start_num = map[r][c];
    
    memset(visited, false, sizeof(visited));
    visited[r][c] = true;

    queue<pair<int, int>> q;
    q.push({r,c});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<1 || ny>n || nx<1 || nx>n) continue;
            if(start_num<=map[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
            possible_max_num = max(possible_max_num, map[ny][nx]);
        }
    }
    if(possible_max_num==-1) return 1; // 더 이상 새로 이동할 위치가 없는 경우

    bool flag = false;
    for(int i=1; i<=n; i++){ // 행 번호도 같은 숫자가 여러개 일경우, 열 번호가 가장 작은 곳으로 이동
        for(int j=1; j<=n; j++){
            if(visited[i][j] && map[i][j] == possible_max_num){ // 도달 불가능한 위치 제외 !!
                r = i; c = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    while(k--) {
        if(move()) break;
    }
    cout << r << " " << c;
}
