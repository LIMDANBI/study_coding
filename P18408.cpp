#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cnt[3]={0};
    int a, b, c; cin >> a >> b >> c;
    cnt[a]++; cnt[b]++; cnt[c]++;
    if(cnt[1]<cnt[2]) cout << 2;
    else cout << 1;
}