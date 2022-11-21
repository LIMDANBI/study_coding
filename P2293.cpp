#include<iostream>
#include<cstring>
#define MAX_N 101
#define MAX_K 10001
using namespace std;

int N, K;
int coin[MAX_N];
int dp[MAX_K];

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> coin[i];
}

void solution() {
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= K; j++) dp[j] = dp[j] + dp[j - coin[i]];
	} cout << dp[K];
}

int main() {
	input();
	solution();
}