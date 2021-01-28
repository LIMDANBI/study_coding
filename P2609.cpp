#include<iostream>
using namespace std;
int main(){
    int n, m, a, b, tmp, gcd, lcm; cin>>n>>m; 
    if(n<m){a=m; b=n;} else {a=n; b=m;}
    while (a%b!=0){
        tmp=b; b=a%b; a=tmp;
    } gcd=b;
    if(n<m){a=m; b=n; lcm=m;} else {a=n; b=m; lcm=n;}
    while(lcm%a!=0||lcm%b!=0) lcm+=gcd;
    cout<<gcd<<'\n'<<lcm;
}