#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, L, U, X; cin >> T;
    for(int t=1; t<=T; t++){
        cin >> L >> U >> X;
        if(X < L) cout << "#" << t << " " << L-X << "\n";
        else if(X>U) cout << "#" << t << " " << -1 << "\n";
        else cout << "#" << t << " " << 0 << "\n";
    }
}