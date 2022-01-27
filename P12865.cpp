#include<iostream>
#define MAX_N 101
#define MAX_K 100001
using namespace std;

int N, K;
int W[MAX_N], V[MAX_N];
int DP[MAX_N][MAX_K];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> W[i] >> V[i];  // 물건들의 무게(w)와 가치(v)
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){ // 배낭의 임시 용량
            if(j<W[i]) DP[i][j] = DP[i-1][j]; // 물건 i의 무게가 배낭의 임시 용량을 초과한 경우 물건 i-1까지만 담음
            else DP[i][j] = max(DP[i-1][j], DP[i-1][j-W[i]]+V[i]);
        }
    }
    cout << DP[N][K];
}