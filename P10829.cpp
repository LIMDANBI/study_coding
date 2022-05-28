#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    vector<int> v;
    while (n>1){
        v.push_back(n%2);
        n/=2;
    }
    if(n==1) cout << n;
    for(int i=v.size()-1; i>=0; i--) cout << v[i];
}