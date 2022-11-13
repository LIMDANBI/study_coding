#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        string bits; cin >> bits;

        int ans = 0;
        for(int i=0; i<bits.size(); i++){
            if(i==0 && bits[0]=='1') ans++;
            else if(i>0 && bits[i-1]!=bits[i]) ans++;
        }

        cout << "#" << t << " " << ans << "\n"; 
    }
}