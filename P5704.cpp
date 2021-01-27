#include<iostream>
#include<string.h>
using namespace std;
int main(){
    while(1){
        int alphabet[26]{}, ispangram=1; string str; getline(cin, str);
        if(str=="*") break;
        else{ 
            for(int i=0; i<str.size(); i++){
                if(str.at(i)!=' ')alphabet[str.at(i)-97]++;
            }
        }
        for(int i=0; i<26; i++){
            if(alphabet[i]==0) {ispangram=0; break;}
        }
        if(ispangram) cout<<"Y"<<'\n';
        else cout<<"N"<<'\n';
    }
}