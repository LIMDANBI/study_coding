#include<iostream>
using namespace std;
int main(){
    int n, c, k, ans=0; cin>>n;
    for(int i=0; i<n; i++){
        cin>>c>>k; if(k!=0)ans+=c*k;
    } cout<<ans;
}