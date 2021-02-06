#include<iostream>
using namespace std;
int main(){
    int n, t, tmp, ans=0, isok=1; cin>>n>>t;
    for(int i=0; i<n; i++){
        cin>>tmp; 
        if(t-tmp>=0&&isok) { t-=tmp; ans++;} else isok=0;
    } cout<<ans;
}