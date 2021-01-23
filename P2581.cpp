#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, m, small=0, sum=0, isprime=1; cin>>n>>m;
    for(int i=n; i<=m; i++){
        for(int j=2; j<=sqrt(i); j++){
            if(i%j==0) { isprime=0; break;}
        }
        if(small==0 && isprime && i!=1) {small=i; sum+=i;}
        else if(isprime && i!=1) sum+=i; isprime=1;
    }
    if(small) cout<<sum<<'\n'<<small;
    else cout<<-1;
}