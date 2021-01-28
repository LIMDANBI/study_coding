#include<iostream>
using namespace std;
int main(){
    int n, m, k, ans=0; cin>>n>>m>>k;
    n/2<m?ans=n/2:ans=m;
    while(m+n-k<2*ans+ans && 0<ans) ans--; cout<<ans;
}