#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    int C[31][31]{};
    for(int i=1; i<31; i++){
        C[i][0]=1; C[i][1]=i; C[i][i]=1;
        for(int j=2; j<i; j++) C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
    for(int i=0; i<t; i++){
        int n, m; cin>>n>>m;
        cout<<C[m][n]<<'\n';
    }
}