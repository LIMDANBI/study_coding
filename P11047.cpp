#include<iostream>
using namespace std;
int main(){
    int n, k, ans=0; cin>>n>>k; int value[11]={};
    for(int i=1; i<=n; i++) cin>>value[i];
    while (k>0){
        if(k<value[n]) n--;
        else {k-=value[n]; ans++; }
    } cout<<ans;
}