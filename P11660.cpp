#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x; cin>>n>>m;
    int dp[n+1][n+1] = {};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) {
            cin>>x;
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + x;
        }
    }
    int x1, y1, x2, y2;
    for(int i=0; i<m; i++){
        cin>>x1>>y1>>x2>>y2;
        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << '\n';
    }
}