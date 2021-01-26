#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    if(n%2==0) cout<<"I LOVE CBNU";
    else{
        for(int i=0; i<n/2+2; i++){
            for(int j=0; j<n; j++){
                if(i==0) cout<<"*";
                else{
                    if(j==n/2-i+1 || j==n/2+i-1) cout<<"*";
                    else if(j<n/2+i) cout<<" ";
                }
            } cout<<'\n';
        }
    }
}