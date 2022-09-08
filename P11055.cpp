#include<iostream>
#define MAX 1001
using namespace std;

int N, ans=0;
int A[MAX], dp[MAX];

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
}

void solution(){
    for(int i=0; i<N; i++){
        dp[i] = A[i];
        for(int j=0; j<=i; j++){
            if(A[i]>A[j]) dp[i] = max(dp[j]+A[i], dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}