#include<iostream>
using namespace std;
int main(){
    char tmp; int alpahbet[26]{}, mx=0;
    while(1){ cin>>tmp;
        if(cin.eof()) break;
        else alpahbet[tmp-97]++;} 
    for(int i=0; i<26; i++){ if(mx<alpahbet[i]) mx=alpahbet[i];} 
    for(int i=0; i<26; i++){ if(mx==alpahbet[i]) {tmp='a'+i; cout<<tmp;}}
}