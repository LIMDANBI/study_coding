#include<iostream>
#define MAX 1001
using namespace std;

int N, ans=0;
int A[MAX], dp[MAX];

void input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
}

void solution(){
    for(int i=1; i<=N; i++){
        dp[i] = 1;
        for(int j=1; j<=i; j++){
            if(A[i]>A[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << ans;
}