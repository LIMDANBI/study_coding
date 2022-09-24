#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
#define INF 987654321
using namespace std;

int n, k, ans=INF;
int r1, c1, r2, c2;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> pos;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            if(map[i][j]) pos.push_back({i,j}); // 벽의 위치 저장
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
}

int bfs(){
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    queue<pair<int,int>> q;
    visited[r1][c1] = true;
    q.push({r1, c1});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<1 || ny>n || nx<1 || nx>n) continue;
            if(visited[ny][nx] || map[ny][nx]) continue;
            q.push({ny,nx});
            visited[ny][nx] = true;
            dist[ny][nx] = dist[y][x]+1;
            if(ny==r2 && nx==c2) return dist[ny][nx];
        }
    }
    return INF;
}

void solution(int idx, int cnt){
    if(cnt==k){
        ans = min(ans, bfs());
        return;
    }
    int y = pos[idx].first;
    int x = pos[idx].second;
    map[y][x] = 0;
    solution(idx+1, cnt+1);
    map[y][x] = 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution(0, 0);
    if(ans==INF) cout << -1;
    else cout << ans;
}