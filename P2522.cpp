#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    for(int i=0; i<2*n-1; i++){
        if(i<n){
            for(int j=0; j<n; j++) j<n-i-1?cout<<" ":cout<<"*";
        }
        else{
            for(int j=0; j<n; j++) j<i-n+1?cout<<" ":cout<<"*";
        } cout<<'\n';
    }
}