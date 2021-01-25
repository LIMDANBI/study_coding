#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int idx=0, maxlen=0; string str[5]; 
    for(int i=0; i<5; i++) { cin>>str[i];
        if(maxlen<str[i].size()) maxlen=str[i].size(); 
    }
    while (idx<maxlen){
        for(int i=0; i<5; i++){
            if(idx<str[i].size()) cout<<str[i].at(idx);
        } idx++;
    }
}