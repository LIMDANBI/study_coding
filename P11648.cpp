#include<iostream>
using namespace std;
int main(){
    string n; int ans=0, tmp=1; cin>>n;
    while (n.size()!=1){
        for(int i=0; i<n.size(); i++) tmp*=n[i]-'0';
        n=to_string(tmp); tmp=1; ans++;
    } cout<<ans;
}