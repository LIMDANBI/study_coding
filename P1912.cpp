#include<iostream>
#define MAX 100001
using namespace std;

int n, ans=-1000;
int seq[MAX], dp[MAX];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> seq[i];
}

void solution(){
    for(int i=1; i<=n; i++){
        dp[i] = max(dp[i-1]+seq[i], seq[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}