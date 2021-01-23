#include<iostream>
using namespace std;

int main(){
    long long n,m; cin>>n>>m;
    if(0<n&&0<m || 0>n&&0>m) m<n?cout<<n-m:cout<<m-n;
    else 0<n?cout<<n-1*m: cout<<m-1*n;
}