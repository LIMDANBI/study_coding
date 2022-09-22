#include<iostream>
#define MAX 101
using namespace std;

int n, m, ans=0;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = {1, 0};
int dx[] = {0, 1};

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> map[i][j];
    }
}

void dfs(int y, int x){
    if(y==n && x==m) ans=1;
    for(int d=0; d<2; d++){
        int ny = y+dy[d];
        int nx = x+dx[d];
        if(ny<1 || ny>n || nx<1 || nx>m) continue; // 범위를 벗어나는 경우
        if(map[ny][nx]==0 || visited[ny][nx]) continue; // 뱀이 있는 경우, 이미 방문한 경우
        visited[ny][nx] = true;
        dfs(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    dfs(1,1);
    cout << ans;
}
