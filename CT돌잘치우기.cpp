#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;

int n, k, m, res, ans=0;
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> pos;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> n >> k >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> map[i][j];
    }
    for(int i=0; i<k; i++){
        int r, c; cin >> r >> c;
        pos.push_back({r,c});
    }
}

void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        res++; q.pop();
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny<1 || ny>n || nx<1 || nx>n) continue; // 범위를 벗어나는 경우
            if(map[ny][nx] || visited[ny][nx]) continue; // 돌이있는 경우, 이미 방문한 경우
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

void solution(int cnt){ // cnt: 치운 돌의 개수
    if(cnt == m){
        res = 0;
        memset(visited, false, sizeof(visited)); // 초기화 중요,,!! ^^
        for(int i=0; i<k; i++){
            int r = pos[i].first;
            int c = pos[i].second;
            if(!visited[r][c]) bfs(r, c);
        }
        ans = max(res, ans);
        return;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j]){ // 돌이 있어 이동할 수 없는 곳
                map[i][j] = 0; // (i, j) 위치의 돌을 치워봄
                solution(cnt+1); // backtracking
                map[i][j] = 1; // 원위치
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution(0);
    cout << ans;
}
