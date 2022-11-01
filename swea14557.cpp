#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        string S; cin >> S;

        int cnt = 0;
        for(int i=0; i<S.size(); i++){
            if(S[i]=='1') cnt++;
        }

        if(cnt%2) cout << "#" << t << " yes\n";
        else cout << "#" << t << " no\n";
    }
}