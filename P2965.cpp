#include<iostream>
using namespace std;
int main(){
    int a, b, c, ans=0; cin>>a>>b>>c;
    while (a!=b-1||c!=b+1){
        if(b-a>c-b){int tmp=b; b--; c=tmp;} 
        else{ int tmp=b; b++; a=tmp;} ans++;
    } cout<<ans;
}