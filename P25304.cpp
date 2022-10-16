#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int X, N; 
    cin >> X >> N;
    int price, cnt, total = 0; 
    while(N--){
        cin >> price >> cnt;
        total += (price*cnt);
    }
    if(total == X) cout << "Yes";
    else cout << "No";
}