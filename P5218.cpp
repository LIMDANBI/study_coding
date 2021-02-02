#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int t; cin>>t; string str1, str2;
    for(int i=0; i<t; i++){
        cin>>str1>>str2; cout<<"Distances:";
        for(int j=0; j<str1.size(); j++){
            if(str1.at(j)<=str2.at(j)) cout<<" "<<str2.at(j)-str1.at(j);
            else cout<<" "<<str2.at(j)+26-str1.at(j);
        } cout<<'\n';
    }
}