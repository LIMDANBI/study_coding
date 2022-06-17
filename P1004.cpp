#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    int x1, y1, x2, y2; // 출발점, 도착점
    int n, cx, cy, r; // 행성계 개수, 행성계의 중점과 반지름
    while (T--){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        int ans = 0;
        while (n--){
            cin >> cx >> cy >> r;
            int dis1 = (x1-cx)*(x1-cx) + (y1-cy)*(y1-cy);
            int dis2 = (x2-cx)*(x2-cx) + (y2-cy)*(y2-cy);
            r*=r;
            if(r>dis1 && r>dis2) continue;
            if(r>dis1) ans++;
            if(r>dis2) ans++; 
        }
        cout << ans << '\n';
    }
}