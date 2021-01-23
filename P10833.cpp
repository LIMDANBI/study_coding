#include<iostream>
using namespace std;

int main(){
    int n, s, a, ans=0; cin>>n;
    for(int i=0; i<n; i++){
        cin>>s>>a; ans+=(a%s);
    } cout<<ans;
}