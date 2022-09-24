#include<iostream>
#include<vector>
#include<queue>
#define MAX 101
#define INF 987654321
using namespace std;

int n, r1, c1, r2, c2;
bool visited[MAX][MAX];
int map[MAX][MAX], dist[MAX][MAX];

int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

void init(){
    cin >> n >> r1 >> c1 >> r2 >> c2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) dist[i][j] = INF;
    }
}

void solution(){
    queue<pair<int, int>> q;
    q.push({r1,c1});
    dist[r1][c1] = 0;
    visited[r1][c1] = true;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<8; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<1 || ny>n || nx<1 || nx>n || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            dist[ny][nx] = dist[y][x]+1; 
            q.push({ny,nx});
        }
    }
}

void output(){
    if(dist[r2][c2]==INF) cout << -1;
    else cout << dist[r2][c2];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solution();
    output();
}