#include <iostream>
using namespace std;

int N, r, c, ans=0;

void Z(int y, int x, int s){
    if(y==r && x==c){
        cout << ans;
        return;
    }
    if(r<y+s && r>=y && c<x+s && c>=x){
        Z(y, x, s/2); // 1사 분면
        Z(y, x+s/2, s/2); // 2사 분면
        Z(y+s/2, x, s/2); // 3사 분면
        Z(y+s/2, x+s/2, s/2); // 4사 분면
    }
    else ans+=s*s;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> r >> c;
    Z(0, 0, (1<<N));
}