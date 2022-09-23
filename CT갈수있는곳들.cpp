#include<iostream>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;

int n, ans=0;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop(); ans++;
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<1 || ny>n || nx<1 || nx>n) continue; // 범위를 벗어난 경우
            if(map[ny][nx] || visited[ny][nx]) continue; // 이동 불가능한 경우, 이미 방문한 경우 
            visited[ny][nx] = true;
            q.push({ny,nx});
        }
    }
}

void solution(){
    int k, r, c;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> map[i][j];
    }
    for(int i=0; i<k; i++){
        cin >> r >> c;
        if(visited[r][c]) continue;
        visited[r][c] = true;
        bfs(r, c);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solution();
}
