#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n+i; j++){
            if(i==0) j==n+i-1?cout<<"*":cout<<" ";
            else if(i==n-1) j%2==0?cout<<"*":cout<<" ";
            else if(n%2==0){
                if(i%2==0){
                    if(j!=0 && j%2!=0 && n-i-2<j) cout<<"*";
                    else cout<<" ";}
                else{
                    if(j!=0 && j%2==0 && n-i-2<j) cout<<"*";
                    else cout<<" ";}
            } else{
                if(i%2!=0){
                    if(j!=0 && j%2!=0 && n-i-2<j) cout<<"*";
                    else cout<<" ";}
                else{
                    if(j!=0 && j%2==0  && n-i-2<j) cout<<"*";
                    else cout<<" ";}
            }
        } cout<<'\n';
    }
}