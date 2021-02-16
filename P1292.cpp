#include<iostream>
using namespace std;
int main(){
    int a, b, ans=0, arr[1001], cnt=1, tmp=1, i=1; cin>>a>>b;
    while(i<=1001){
        if(tmp==0){cnt++; tmp=cnt;}
        else{ arr[i]=cnt; tmp--; i++;}
    } for(int i=a; i<=b; i++) ans+=arr[i]; cout<<ans;
}