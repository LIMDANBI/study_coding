#include<iostream>
#define MOD 1000000000
#define MAX 1000001
using namespace std;

int n, sign=1, dp[MAX];

void solution(){
    // 부호 
    if(n<0) {
        if(n%2==0) sign=-1;
        n*=-1;
    }
    else if(n==0) sign=0;

    // dynamic programming
    dp[0]=0; dp[1]=1;
    for(int i=2; i<=n; i++) dp[i] = (dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
    cout << sign << "\n" << dp[n];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    solution();
}