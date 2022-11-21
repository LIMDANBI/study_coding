#include<vector>
#include<iostream>
#include<algorithm>
#define MAX 7
using namespace std;
 
int num[MAX];
vector<int> v;
 
void input() {
    v.clear();
    for (int i = 0; i < MAX; i++) cin >> num[i];
}
 
void solution(int cnt, int sum, int idx) {
    if (cnt == 3) {
        v.push_back(sum);
        return;
    }
    for (int i = idx; i < MAX; i++) {
        solution(cnt + 1, sum + num[i], i + 1);
    }
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        solution(0, 0, 0);
        sort(v.begin(), v.end(), greater<int>());
        unique(v.begin(), v.end()); // sort 후 !!
        cout << "#" << t << " " << v[4] << "\n";
    }
}