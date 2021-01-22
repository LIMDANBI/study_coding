#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string n; cin>>n;
    if(n=="0") cout<<"0";
    else{
        for(int i=0; i<n.size(); i++){
            if(n.at(i)=='0') cout<<"000";
            else if(n.at(i)=='1') i==0?cout<<"1":cout<<"001";
            else if(n.at(i)=='2') i==0?cout<<"10":cout<<"010";
            else if(n.at(i)=='3') i==0?cout<<"11":cout<<"011";
            else if(n.at(i)=='4') cout<<"100";
            else if(n.at(i)=='5') cout<<"101";
            else if(n.at(i)=='6') cout<<"110";
            else if(n.at(i)=='7') cout<<"111";
        }
    }
}