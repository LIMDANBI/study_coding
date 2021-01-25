#include<iostream>
using namespace std;
int main(){
    int t, k, n; cin>>t;
    for(int i=0; i<t; i++){
        cin>>k>>n; int num[k+1][n+1]{};
        for(int j=1; j<=n; j++) num[0][j]=j;
        for(int j=1; j<=k; j++){
            for(int l=1; l<=n; l++){
                if(l==1) num[j][l]=1;
                else num[j][l]=num[j][l-1]+num[j-1][l];
            }
        } cout<<num[k][n]<<'\n';
    }
}