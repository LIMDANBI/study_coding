#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    float a, b; cin >> a >> b;
    a-=a*(b/100);
    if(a>=100) cout << 0;
    else cout << 1;
}