#include<iostream>
using namespace std;
int main(){
    string str, ans=""; cin>>str; int tmp=0, isok=1;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='.'){
            if(tmp==4) ans+="AAAA.";
            else if(tmp==2) ans+="BB.";
            else if(tmp==0) ans+=".";
            else { isok=0; break;} tmp=0;
        } else {
            tmp++; if(tmp==4) { ans+="AAAA"; tmp=0;}
        }
    } if(tmp==2) ans+="BB"; else if(tmp==1 || tmp==3) isok=0; isok?cout<<ans:cout<<-1;
}