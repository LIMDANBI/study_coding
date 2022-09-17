#include<iostream>
using namespace std;

int N, B;
char digit[40] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void solution(){
    string ans = "";
    while(N>0){
        ans=digit[(N%B)]+ans;
        N/=B;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> B;
    solution();
}