#include<iostream>
#include<queue>
#define MAX 50
using namespace std;

int T, M, N, K;
int field[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y){
    field[x][y] = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        else if(field[nx][ny]==1) bfs(nx, ny);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--){
        cin >> M >> N >> K;
        queue<pair<int, int> > q; 
        int x, y, ans=0;
        for(int i=0; i<K; i++){
            cin >> x >> y;
            q.push({x,y});
            field[x][y] = 1;
        }
        while (!q.empty()){
            int x = q.front().first, y = q.front().second;
            if(field[x][y]==1) {
                bfs(x, y);
                ans++;
            }
        }
        cout << ans << "\n"; 
    }
}