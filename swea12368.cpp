#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, A, B; cin >> T;
    for(int t=1; t<=T; t++){
        cin >> A >> B;
        cout << "#" << t << " " << (A+B)%24 << "\n";
    }
}