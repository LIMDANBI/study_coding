#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n, tmp, ans=0; cin>>n;
        for(int j=0; j<n; j++){
            cin>>tmp; ans+=tmp;
        } cout<<ans<<'\n';
    }
}