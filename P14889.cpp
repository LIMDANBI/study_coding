#include<iostream>
#include<vector>
#define MAX 21
#define INF 987654321
using namespace std;

bool is_satrt[MAX];
int ability[MAX][MAX];
int N, total = 0, ans = INF;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ability[i][j];
            total += ability[i][j];
        }
    }
}

int get_score(int who) {
    int res = 0;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        if (is_satrt[i]==who) v.push_back(i);
    }
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i; j < v.size(); j++) res += (ability[v[i]][v[j]] + ability[v[j]][v[i]]);
    }
    return res;
}

void solution(int idx, int cnt) { // 스타트 팀과 링크 팀의 능력치의 차이의 최솟값
    if (cnt == N / 2) {
        int start = get_score(1);
        int link = get_score(0);
        ans = min(ans, abs(start - link));
        return;
    }
    for (int i = idx; i < N; i++) {
        is_satrt[i] = true;
        solution(i + 1, cnt + 1);
        is_satrt[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution(0, 0);
    cout << ans;
}