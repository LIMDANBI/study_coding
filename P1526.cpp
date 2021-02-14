#include<iostream>
using namespace std;
int main(){
    int n; cin>>n; n++;
    while (n--){
        string str=to_string(n); int isok=1;
        for(int i=0; i<str.size(); i++){
            if(str[i]!='4' && str[i]!='7') isok=0;
        } if(isok) break;
    } cout<<n;
}