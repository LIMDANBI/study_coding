#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string str; cin>>str; int start=0, ans=0;
    for(int i=0; i<str.size(); i++){
        if(str.at(i)==',') {int tmp=std::stoi(str.substr(start, i)); ans+=tmp; start=i+1;}
    } int tmp=std::stoi(str.substr(start, str.size())); ans+=tmp; cout<<ans;
}