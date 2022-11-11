#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    int x1, y1, x2, y2, x3, y3, x4, y4, ans;
    while (T--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        ans = (x2-x1) * (y2-y1) - (max((min(x2, x4)-max(x1, x3)), 0) * max((min(y2, y4)-max(y1, y3)), 0));
        cout << ans << "\n"; 
    }
}