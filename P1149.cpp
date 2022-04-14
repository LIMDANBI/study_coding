#include<iostream>
#define MAX 1001
using namespace std;

int dp[MAX][3];
int N, red, green, blue;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> red >> green >> blue;
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + red; // 이전 집 green or blue
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + green; // 이전 집 red or blue
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + blue; // 이전 집 red or green
    }
    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]); // 모든 집을 칠하는 비용의 최솟값
}