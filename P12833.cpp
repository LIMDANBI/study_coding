#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A, B, C; cin >> A >> B >> C;
    C%=2; while (C--) A^=B;
    cout << A;
}