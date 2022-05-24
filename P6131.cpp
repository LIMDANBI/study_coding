#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans=0; cin >> n;
    for(int i=1; i<=500; i++){ // A
        for(int j=1; j<=i; j++){ // B
            if(i*i == j*j+n) ans++; // A의 제곱은 B의 제곱보다 N만큼 커
        }
    }
    cout << ans;
}