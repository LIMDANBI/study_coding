#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string str; cin>>str; int idx=(str.size()-1)/2;
        if(str.at(idx)==str.at(idx+1)) cout<<"Do-it"<<'\n';
        else cout<<"Do-it-Not"<<'\n';
    }
}