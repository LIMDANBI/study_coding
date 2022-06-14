#include <iostream>
#include <cstring>
#include <queue>
#define MAX 101
using namespace std;

int N, ans=0;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(int h){
    memset(visit, false, sizeof(visit));
    queue<pair<int, int>> q;
    int res = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(map[i][j]>h && !visit[i][j]){
                q.push({i, j});
                visit[i][j] = true;
                res++;
                while (!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int d=0; d<4; d++){
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(ny<1 || ny>N || nx<1 || nx>N || map[ny][nx]<=h || visit[ny][nx]) continue;
                        visit[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int max_val = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
            max_val = max(max_val, map[i][j]);
        }
    }
    for(int i=0; i<=max_val; i++) ans = max(ans, bfs(i));
    cout << ans;
}