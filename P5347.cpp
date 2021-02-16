#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    while (n--){
        long long a, b, gcd; cin>>a>>b; long long n=a, m=b;
        while (n%m){
            long long tmp=m; m=n%m; n=tmp;
        } gcd=m; cout<<a*b/gcd<<'\n';
    }
}