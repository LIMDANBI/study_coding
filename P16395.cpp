#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin>>n>>k;
    int pascal[31][31]{};
    for(int i=1; i<=n; i++){ // dp를 이용하여 파스칼 삼각형을 만듦
        pascal[i][1]=1; pascal[i][i]=1;
        for(int j=2; j<i; j++) pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
    } 
    cout<<pascal[n][k];
}