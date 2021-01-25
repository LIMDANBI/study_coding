#include<iostream>
using namespace std;
int main(){
    int n, k; cin>>n>>k; int C[11][11]{};
    for(int i=1; i<=n; i++){
        C[i][1]=i; C[i][i]=1; C[i][0]=1;
        for(int j=2; j<i; j++) C[i][j]= C[i-1][j-1]+C[i-1][j];
    } cout<<C[n][k];
}