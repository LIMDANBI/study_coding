#include<iostream>
using namespace std;
int main(){
    string id; cin>>id;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) i==1&&j==1?cout<<":"<<id<<":":cout<<":fan:"; cout<<'\n';
    }
}