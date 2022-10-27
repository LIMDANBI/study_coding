#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        int N; cin >> N;
        if(N%2==0) cout << "#" << t << " Alice\n";
        else cout << "#" << t << " Bob\n";
    }
}