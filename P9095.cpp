#include <iostream>
using namespace std;

int main(){
    int dp[12] = {0, 1, 2, 4};
    for(int i=4; i<12; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    int t; cin >> t;
    for(int i=0; i<t; i++){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}