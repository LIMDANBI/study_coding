#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n+i; j++){
            if(i==0) j==n+i-1?cout<<"*":cout<<" ";
            else if(i==n-1) cout<<"*";
            else{
                if(j==n+i-1||j==n-i-1) cout<<"*";
                else cout<<" ";
            }
        } cout<<'\n';
    }
}