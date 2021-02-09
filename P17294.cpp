#include<iostream>
using namespace std;
int main(){
    string str; cin>>str; int d, isin=1; if(str.size()!=1) d=str[0]-str[1];
    for(int i=2; i<str.size(); i++){
        if(str[i-1]-str[i]!=d) isin=0; 
    } if(isin) cout<<"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!"; else cout<<"흥칫뿡!! <(￣ ﹌ ￣)>";
}