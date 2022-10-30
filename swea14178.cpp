#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        int N, D; cin >> N >> D;
        int ans = N/(D*2+1);
        if(N%(D*2+1)) ans++;
        cout << "#" << t << " " << ans << "\n";
    }
}