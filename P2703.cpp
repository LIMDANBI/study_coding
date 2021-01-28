#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int t; cin>>t; string str, str2; getline(cin, str);
    for(int i=0; i<t; i++){
        char cryptoquote[26]; getline(cin, str); getline(cin, str2);
        for(int j=0; j<26; j++) cryptoquote[j]=str2.at(j);
        for(int j=0; j<str.size(); j++){
            if(str.at(j)==' ') cout<<' ';
            else cout<<cryptoquote[str.at(j)-65];
        } cout<<'\n';
    }
}