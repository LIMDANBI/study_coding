#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int S, T, D; cin >> S >> T >> D;
    cout << D/(S*2)*T;
}