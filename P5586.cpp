#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int ioi=0, joi=0; string str; cin>>str;
    for(int i=0; i<str.size()-2; i++){
        if(str.substr(i,3)=="IOI") ioi++;
        else if(str.substr(i,3)=="JOI") joi++;
    }  cout<<joi<<'\n'; cout<<ioi<<'\n';
}