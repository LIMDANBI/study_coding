#include<iostream>
using namespace std;

void hanoi(int n, int s, int e, int tmp){
    if(n==1)
        cout << s << " " << e << "\n";
    else{
        hanoi(n-1, s, tmp, e);
        cout << s << " " << e << "\n";
        hanoi(n-1, tmp, e, s);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cout << (1<<n)-1 << "\n";
    hanoi(n, 1, 3, 2);
}