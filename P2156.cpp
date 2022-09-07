#include<iostream>
#define MAX 10001
using namespace std;

int N, wine[MAX], dp[MAX];

void input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> wine[i];
}

void solution(){
    dp[1] = wine[1];
    dp[2] = wine[1]+wine[2];
    for(int i=3; i<=N; i++) dp[i] = max(max(dp[i-2]+wine[i], dp[i-3]+wine[i-1]+wine[i]), dp[i-1]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << dp[N];
}