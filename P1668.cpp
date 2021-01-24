#include<iostream>
using namespace std;

int main(){
    int n, left=0, right=0, lmx=0, rmx=0; cin>>n; int trophy[n];
    for(int i=0; i<n; i++){
        cin>>trophy[i]; 
        if(lmx<trophy[i]){ left++; lmx=trophy[i];}
    }
    for(int i=n-1; -1<i; i--){ 
        if(rmx<trophy[i]){right++; rmx=trophy[i];}
    } cout<<left<<'\n'<<right;
}