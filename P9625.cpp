#include<iostream>
using namespace std;
int main(){
    int k, A[46]={1,0}, B[46]{0,1}; cin>>k;
    for(int i=2; i<=k; i++){
        A[i]=A[i-1]+A[i-2]; B[i]=B[i-1]+B[i-2];
    } cout<<A[k]<<" "<<B[k];
}