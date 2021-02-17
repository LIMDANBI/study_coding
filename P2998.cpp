#include<iostream>
using namespace std;
int main(){
    string str; cin>>str; int idx=0;
    if(str.size()%3==1){ 
        if(str[0]) cout<<str[0]; idx=1;
    } else if(str.size()%3==2){ 
        cout << (str[0]-48)*2+(str[1]-48)*1; idx=2;
    } while (idx<str.size()){
        cout<<(str[idx]-48)*4+(str[idx+1]-48)*2+(str[idx+2]-48); idx+=3;
    }
}