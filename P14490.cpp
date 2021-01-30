#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string str; int a, b, n, m, idx; cin>>str;
    while (str.at(idx)!=':') idx++; n=std::stoi(str.substr(0,idx)); m=std::stoi(str.substr(idx+1, str.size())); a=n; b=m;
    while (a%b){
        int tmp=b; b=a%b; a=tmp;
    } cout<<n/b<<":"<<m/b;
}