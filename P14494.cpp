#include<iostream>
using namespace std;
int main(){
    int n, m; cin>>n>>m; long long dp[1001][1001], mod=1000000007;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 || j==1) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j]%mod+dp[i][j-1]%mod+dp[i-1][j-1]%mod;
        }
    } cout<<dp[n][m]%mod;
}