#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string n; int b, ans=0; cin>>n>>b; long long arr[n.size()];
    for(int i=n.size()-1; -1<i; i--){
        if(i==n.size()-1) arr[i]=1;
        else arr[i]=arr[i+1]*b;
        if(48<=n.at(i)&&n.at(i)<=57) ans+=(n.at(i)-48)*arr[i];
        else ans+=(n.at(i)-55)*arr[i];
    } cout<<ans;
}