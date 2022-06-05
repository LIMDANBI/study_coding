#include <iostream>
#define MAX 1000000
#define MOD 1000000009
using namespace std;

long long dp[MAX] = {0, 1, 2, 4};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;

    int startIdx = 4;
    for(int i=0; i<T; i++){
        int n; cin >> n;
        for(int j=startIdx; j<=n; j++){
            dp[j] = (dp[j-1]+dp[j-2]+dp[j-3])%MOD;
            startIdx++;
        }
        cout << dp[n] << '\n';
    }
}