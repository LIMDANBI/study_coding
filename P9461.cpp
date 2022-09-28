#include<iostream>
#define MAX 101
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T, N;
    long long dp[MAX];
    for(int i=1; i<MAX; i++){ // dynamic programming
        if(i<=3) dp[i] = 1;
        else dp[i] = dp[i-2]+dp[i-3]; // 점화식
    }

    cin >> T;
    while(T--){ // print answer
        cin >> N;
        cout << dp[N] << "\n";
    }
}