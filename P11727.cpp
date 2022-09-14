#include<iostream>
#define MAX 1001
#define DIV 10007
using namespace std;

int n, dp[MAX] = {0, 1, 3, };

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=3; i<=n; i++) dp[i] = (dp[i-1]+2*dp[i-2])%DIV;
    cout << dp[n];
}