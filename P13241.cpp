#include<iostream>
using namespace std;
int main(){
    long long n, m, a, b, tmp; cin>>n>>m; if(n<m){a=m; b=n;} else{a=n; b=m;}
    while (a%b!=0) {
        tmp=b; b=a%b; a=tmp; 
    } cout<<n*m/b;
}