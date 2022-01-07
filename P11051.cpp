#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin>>n>>k;
    int C[1001][1001]{};
    for(int i=1; i<=n; i++){
        C[i][0]=1; C[i][1]=i; C[i][i]=1;
        for(int j=2; j<i; j++) C[i][j] = (C[i-1][j]+C[i-1][j-1])%10007;
    } cout<<C[n][k];
}