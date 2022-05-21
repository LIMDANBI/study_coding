#include <iostream>
#include <cstring>
#include <queue>
#define MAX 50
using namespace std;

int w, h;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i,j});
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<8; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=h || nx<0 || nx>=w) continue; // 범위를 벗어나는 경우
            if(visit[ny][nx] || map[ny][nx]==0) continue; // 이미 방문한 경우, 바다인 경우
            visit[ny][nx] = true;
            q.push({ny,nx});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (1){
        int ans = 0;
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        cin >> w >> h;
        if(w==0 && h==0) break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++) cin >> map[i][j];
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(visit[i][j] || map[i][j]==0) continue; // 이미 방문한 경우, 바다인 경우
                visit[i][j] = true;
                bfs(i, j);
                ans++;
            }
        }
        cout << ans << "\n";
    }
}