#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string num1, num2, ans=""; cin>>num1>>num2;
    int idx1=num1.size()-1, idx2=num2.size()-1, tmp, carry=0, begin=0;
    while(idx1>=0 && idx2>=0){
        tmp=(num1.at(idx1)-48)+(num2.at(idx2)-48)+carry; carry=0;
        if(tmp>1) {carry=1; tmp%=2;} ans=to_string(tmp)+ans;
        idx1--; idx2--;
    }
    if(idx1==-1){
        while (idx2>=0){
            tmp=(num2.at(idx2)-48)+carry; carry=0; idx2--;
            if(tmp>1) {carry=1; tmp%=2;} ans=to_string(tmp)+ans;
        }
    }
    else if(idx2==-1){
        while (idx1>=0){
            tmp=(num1.at(idx1)-48)+carry; carry=0; idx1--;
            if(tmp>1) {carry=1; tmp%=2;} ans=to_string(tmp)+ans;
        }
    }
    if(carry) ans=to_string(carry)+ans;
    for(int i=0; i<ans.size(); i++){
        if(ans.at(i)=='0') begin=i+1;
        else break;
    }
    if(begin==ans.size()) cout<<"0";
    else cout<<ans.substr(begin);
}