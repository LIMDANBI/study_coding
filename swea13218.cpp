#include<iostream>
using namespace std;

int main(){
    int T, N; cin >> T;
    for(int t=1; t<=T; t++){
        cin >> N;
        cout << "#" << t << " " << N/3 << "\n";
    }
}