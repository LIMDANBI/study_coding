#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
 
int  N, M, K;
int consumer[MAX];
 
void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> consumer[i];
    sort(consumer, consumer + N);
}
 
string solution() {
     
    int idx = 0, buns = 0;
    for (int sec = 0; sec <= consumer[N - 1]; sec++) {
        if (sec!=0 && sec % M == 0) buns += K;
        while (consumer[idx] == sec) {
            if (buns>0) buns--;
            else return "Impossible";
            idx++;
        }
    }
    return "Possible";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}