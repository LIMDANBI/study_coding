#include <iostream>
using namespace std;

int board[51][51], visited[51][51], dp[51][51];
int n, m;

// 오른쪽 왼쪽 위 아래 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int y, int x){
    if(y<1 || x<1 || y>n || x>m || board[y][x]==24) return 0;
    if(visited[y][x]){
        cout << -1;
        exit(0);
    }
    if(dp[y][x]) return dp[y][x];
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i]*(board[y][x]);
        int nx = x + dx[i]*(board[y][x]);
        dp[y][x] = max(dp[y][x], dfs(ny, nx)+1);
    }
    visited[y][x] = 0;
    return dp[y][x];
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        string str; cin>>str;
        for(int j=1; j<=m; j++) 
            board[i][j] = str[j-1]-48; // H-48==24
    }
    cout << dfs(1, 1);
}