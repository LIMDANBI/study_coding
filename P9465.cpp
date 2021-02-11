#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int score[3][100001]{}, n; cin>>n;
        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++) cin>>score[i][j];
        } int dp[3][100001]{}; dp[1][1]=score[1][1]; dp[2][1]=score[2][1];
        for(int i=2; i<=n; i++){
            dp[1][i]=max(score[1][i]+dp[2][i-1], score[1][i]+dp[0][i-1]);
            dp[2][i]=max(score[2][i]+dp[1][i-1], score[2][i]+dp[0][i-1]);
            dp[0][i]=max(dp[1][i-1],dp[2][i-1]);
        } cout<<max(dp[1][n],dp[2][n]); cout<<'\n';
    }
}