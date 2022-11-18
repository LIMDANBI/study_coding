#include<iostream>
#include<cstring>
#include<vector>
#define MAX 9
#define CARD 19
using namespace std;
 
int win, lose;
int gy_card[MAX], yy_card[MAX];
bool check[CARD], visited[MAX];
 
void init() {
    win = 0; lose = 0;
    memset(check, false, sizeof(check));
}
 
void input() {
    for (int i = 0; i < MAX; i++) {
        cin >> gy_card[i];
        check[gy_card[i]] = true;
    }
 
    int idx = 0;
    for (int i = 1; i < CARD; i++) {
        if (check[i]) continue;
        yy_card[idx++] = i;
    }
}
 
void permutation(int cnt, int gy_score, int yy_score) {
    if (cnt == MAX) {
        if (gy_score < yy_score) lose++;
        else if (gy_score > yy_score) win++;
        return;
    }
    for (int i = 0; i < MAX; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        int score = gy_card[cnt] + yy_card[i];
        if (gy_card[cnt] < yy_card[i]) permutation(cnt + 1, gy_score, yy_score + score);
        else if (gy_card[cnt] > yy_card[i]) permutation(cnt + 1, gy_score + score, yy_score);
        visited[i] = false;
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        input();
        permutation(0, 0, 0);
        cout << "#" << t << " " << win << " " << lose << "\n";
    }
}