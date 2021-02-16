#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while (t--){
        int tmp; cin>>tmp;
        for(int i=0; i<tmp; i++){
            for(int j=0; j<tmp; j++){
                if(i==0 || i==tmp-1) cout<<"#";
                else{
                    if(j==0 || j==tmp-1) cout<<"#";
                    else cout<<"J";}
            } cout<<'\n';
        } cout<<'\n';
    }
}