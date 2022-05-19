#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

struct Data{ int y, x; };
queue<Data> q;

int N, M, ans=0;
bool visit[MAX][MAX];
int space[MAX][MAX], dist[MAX][MAX];
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void findDist(){
    while (!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        for(int d=0; d<8; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<1 || ny>N || nx<1 || nx>M) continue; // 범위를 벗어나는 경우
            if(visit[ny][nx] || space[ny][nx]) continue; // 이미 방문한 경우, 상어인 경우
            q.push({ny,nx});
            visit[ny][nx] = true;
            dist[ny][nx] = dist[y][x]+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> space[i][j];
            if(space[i][j]) q.push({i, j}); // 아기상어 위치 저장
        }
    }
    findDist();
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) ans = max(ans, dist[i][j]); // 안전거리 최대값
    }
    cout << ans;
}