#include<iostream>
using namespace std;
int main(){
    int s=0, t=0, tmp;
    for(int i=0; i<4; i++){ cin>>tmp; s+=tmp;}
    for(int i=0; i<4; i++){ cin>>tmp; t+=tmp;}
    s>=t?cout<<s:cout<<t;
}