#include<iostream>
using namespace std;
int main(){
    int n; cin>>n; string ans="", file[51]{};
    for(int i=0; i<n; i++) cin>>file[i];
    for(int i=0; i<file[0].size(); i++){
        int incommon=1;
        for(int j=1; j<n; j++){
            if(file[j-1][i]!=file[j][i]) {incommon=0; break;}
        } incommon?ans+=file[0][i]:ans+="?";
    } cout<<ans;
}