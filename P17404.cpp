#include<iostream>
#define MAX_N 1001
#define MAX 1000001
using namespace std;

int N, ans=MAX;
int cost[MAX_N][3], dp[MAX_N][3]; // d[i][j] : i번 집을 j로 칠했을 때, 1~i번 집을 칠하는 비용의 최솟값

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++) cin >> cost[i][j];
    }
    for(int first=0; first<3; first++){ // 1번 집 색
        for(int i=0; i<3; i++){
            if(i==first) dp[1][i] = cost[1][i]; // 1번 집 색 고정 (0:red, 1:green, 2:blue)
            else dp[1][i] = MAX; // 고려하지 않기 위해 MAX 값 부여
        }
        for(int i=2; i<=N; i++){ // dp
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }
        for(int i=0; i<3; i++){
            if(i==first) continue; // 마지막 집은 다른 first가 아닌 색상만 가능
            ans = min(ans, dp[N][i]);
        }
    }
    cout << ans;
}