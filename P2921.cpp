#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, ans=0; cin >> N;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++) ans+=(i+j);
    }
    cout << ans;
}