#include<iostream>
using namespace std;
int main(){
    int w, n, p, tmp, ans=0; cin>>w>>n>>p;
    for(int i=0; i<p; i++){
        cin>>tmp; if(w<=tmp&&tmp<=n) ans++;
    } cout<<ans;
}