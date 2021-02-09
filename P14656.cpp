#include<iostream>
using namespace std;
int main(){
    int n, tmp, ans=0; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>tmp; if(tmp!=i)ans++;
    } cout<<ans;
}