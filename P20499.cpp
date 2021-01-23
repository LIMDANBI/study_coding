#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main(){
    char str[8]; cin>>str; int token[3]; int idx=0;
    char *tmp = strtok(str,"/");
    while (tmp!=NULL){ token[idx]=std::stoi(tmp); idx++; tmp = strtok(NULL,"/");}
    if((token[0]+token[2])<token[1] || token[1]==0) cout<<"hasu"; else cout<<"gosu";
}