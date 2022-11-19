#include<iostream>
#include<cstring>
#include<vector>
#define MAX_N 101
#define MAX_K 1001
using namespace std;
 
int N, K;
int dp[MAX_N][MAX_K];
vector<pair<int, int>> item;
 
void input() {
    item.clear();
    memset(dp, 0, sizeof(dp));
     
    cin >> N >> K;
 
    int v, c;
    item.push_back({ 0,0 }); // for start index 1
    for (int i = 0; i < N; i++) {
        cin >> v >> c;
        item.push_back({ v,c });
    }
}
 
int solution() {
    for (int i = 1; i <=N; i++) { // item 개수
        for (int j = 1; j <= K; j++) { // 배낭의 최대 부피 
            if (j < item[i].first) dp[i][j] = dp[i - 1][j]; // 넣을 수 없는 경우
            else dp[i][j] = max(dp[i - 1][j - item[i].first] + item[i].second, dp[i - 1][j]); // 넣을 수 있는 경우
        }
    }
    return dp[N][K];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}