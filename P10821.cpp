#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string str; cin>>str; int ans=1;
    for(int i=0; i<str.size(); i++){
        if(str.at(i)==',') ans++;
    } cout<<ans;
}