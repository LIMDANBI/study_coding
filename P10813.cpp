#include<iostream>
using namespace std;
int main(){
    int n, m, j, k, tmp, basket[101]{}; cin>>n>>m;
    for(int i=1; i<=n; i++) basket[i]=i;
    for(int i=0; i<m; i++){
        cin>>j>>k;
        tmp=basket[j];
        basket[j]=basket[k];
        basket[k]=tmp;
    } for(int i=1; i<=n; i++) cout<<basket[i]<<" ";
}