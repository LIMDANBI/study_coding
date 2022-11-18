#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
vector<int> cryptogram;
 
void input() {
 
    // init
    cryptogram.clear();
 
    int N; cin >> N;
    int tmp;
    while (N--) {
        cin >> tmp;
        cryptogram.push_back(tmp);
    }
}
 
void solution() {
    int N;  cin >> N;
 
    char cmd;
    int x, y, s;
    queue<int> q;
    while (N--) {
        cin >> cmd >> x >> y;
        for (int i = x; i < cryptogram.size(); i++) q.push(cryptogram[i]);
        int tmp = cryptogram.size() - x;
        while (tmp--) cryptogram.pop_back();
        while (y--) {
            cin >> tmp;
            cryptogram.push_back(tmp);
        }
        while (!q.empty()) {
            cryptogram.push_back(q.front());
            q.pop();
        }
    }
}
 
void output(int t) {
    cout << "#" << t << " ";
    for (int i = 0; i < 10; i++) cout << cryptogram[i] << " ";
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int t = 1; t <= 10; t++) {
        input();
        solution();
        output(t);
    }
}