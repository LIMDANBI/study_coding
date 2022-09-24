#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
#define INF 987654321
using namespace std;

int n, m;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];
            dist[i][j] = INF;
        }
    }
}

void solution(){
    queue<pair<int,int>> q;
    q.push({1,1});
    visited[1][1] = true;
    dist[1][1] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<1 || ny>n || nx<1 || nx>m) continue;
            if(map[ny][nx]==0 || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            dist[ny][nx] = min(dist[ny][nx], dist[y][x]+1);
            q.push({ny,nx});
        }
    }
    if(dist[n][m]==INF) cout << -1;
    else cout << dist[n][m];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}
