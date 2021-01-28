#include<iostream>
#include<string.h>
using namespace std;
int main(){
    for(int i=0; i<3; i++){ 
        string str; cin>>str; int max=0, tmp=1;
        for(int j=0; j<8; j++){
            if(j!=0 && str.at(j)==str.at(j-1)) tmp++;
            else tmp=1;
            if(max<tmp) max=tmp;
        } cout<<max<<'\n';
    }
}