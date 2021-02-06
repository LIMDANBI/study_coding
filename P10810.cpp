#include<iostream>
using namespace std;
int main(){
    int n, m, i, j, k, basket[101]{}; cin>>n>>m;
    for (int l=0; l<m; l++){
        cin>>i>>j>>k; for(int t=i; t<=j; t++) basket[t]=k;
    } for (int l=1; l<=n; l++) cout<<basket[l]<<" ";
}