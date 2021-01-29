#include<iostream>
using namespace std;
int main(){
    int n, a, b; cin>>n>>a;
    for(int i=1; i<n; i++){
        cin>>b; int c=a, d=b;
        while (c%d){
            int tmp=d; d=c%d; c=tmp;
        } cout<<a/d<<"/"<<b/d<<'\n';
    }
}