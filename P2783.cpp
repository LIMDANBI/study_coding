#include<iostream>
using namespace std;
int main(){
    cout<<fixed; cout.precision(2);
    int y, x, n; double ans; cin>>x>>y>>n; ans=x*(1000/(double)y);
    for(int i=0; i<n; i++){
        cin>>x>>y; double tmp=x*(1000/(double)y);
        if(tmp<ans) ans=tmp;
    } cout<<ans;
}