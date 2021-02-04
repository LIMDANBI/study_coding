#include<iostream>
#include<string>
using namespace std;
int main(){
    int t; cin>>t;
    for(int i=1; i<=t; i++){
        int l, incorrect=0; string str1, str2;
        cin>>l; cin>>str1>>str2;
        for(int j=0; j<l; j++){
            if(str1[j]!=str2[j]) incorrect++;
        } cout<<"Case "<<i<<": "<<incorrect<<'\n';
    }
}