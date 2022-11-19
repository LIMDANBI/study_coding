#include<iostream>
#include<vector>
using namespace std;
 
int N, L, ans;
vector<pair<int, int>> v;
 
void input() {
 
    // for init
    ans = 0;
    v.clear();
 
    int T, K; 
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> T >> K;
        v.push_back({ T, K });
    }
 
}
 
void dfs(int cnt, int taste, int kcal) {
    if (L < kcal) return;
    if (cnt == N) {
        ans = max(ans, taste);
        return;
    }
    dfs(cnt + 1, taste+v[cnt].first, kcal + v[cnt].second);
    dfs(cnt + 1, taste, kcal);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        dfs(0, 0, 0);
        cout << "#" << t << " " << ans << "\n";
    }
}