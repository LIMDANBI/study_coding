#include<iostream>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;

int n, m, ans=0;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> map[i][j];
    }
}

void solution(){
    queue<pair<int, int>> q;
    q.push({0,0});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue; // 범위를 벗어나는 경우
            if(visited[ny][nx] || map[ny][nx]==0) continue; // 이미 방문한 경우, 뱀이 있는 경우
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    if(visited[n-1][m-1]) ans =1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << ans;
}
