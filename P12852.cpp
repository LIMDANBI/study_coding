#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int N, dp[MAX], before[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    before[1] = 1;
    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1]+1; // 방법 3. 1 빼기
        before[i] = i-1;
        if(i%3==0){ // 방법 1. 3으로 나누기
            if(dp[i/3]+1<dp[i]){
                dp[i] = dp[i/3]+1;
                before[i] = i/3;
            }
        }
        if(i%2==0){ // 방법 2. 2로 나누기
            if(dp[i/2]+1<dp[i]){
                dp[i] = dp[i/2]+1;
                before[i] = i/2;
            }
        }
    }
    cout << dp[N] << "\n";
    cout << N << " ";
    while (N!=1){ // 역추적 
        N = before[N];
        cout << N << " ";
    }
}