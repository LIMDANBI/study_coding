#include<iostream>
#include<vector>
using namespace std;

#define M 1000000007

int main(){
    vector<long long> v(1000001); v[1]=1;
    int n; cin>>n;
    for(int i=2; i<=n; i++){
        v[i] = (v[i-1]+v[i-2])%M;
    }
    cout << v[n];
}