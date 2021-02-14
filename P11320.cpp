#include<iostream>
using namespace std;
int main(){
    int t, a, b; cin>>t;
    while(t--){
        cin>>a>>b;
        if(a==b)cout<<1<<'\n';
        else cout<<(a*a)/(b*b)<<'\n';
    }
}