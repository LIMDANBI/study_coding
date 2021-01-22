#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string n, ans=""; cin>>n; int size=n.size(), idx=0;
    if(size%3==0){
        cout<<(n.at(idx+2)-48)+(n.at(idx+1)-48)*2+(n.at(idx)-48)*4; idx+=3; 
    }
    else if(size%3==2){
        cout<< ((n.at(idx)-48)*2+n.at(idx+1)-48); idx+=2;
    }
    else{
        cout<<n.at(idx)-48; idx+=1;
    }
    while (idx<size){
        cout<<(n.at(idx+2)-48)+(n.at(idx+1)-48)*2+(n.at(idx)-48)*4; idx+=3; 
    }
}