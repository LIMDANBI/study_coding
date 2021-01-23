#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    for(int i=0; i<2*n-1; i++){
        if(i<n){ for(int j=0; j<i+1; j++) cout<<"*";}
        else{ for(int j=0; j<2*n-i-1; j++) cout<<"*";} cout<<'\n';
    }
}