#include<iostream>
using namespace std;
int main(){
    string n; cin>>n; int bar=0, isok=0;
    while (bar<n.size()-1){
        int a=1, b=1; bar++;
        for(int i=0; i<bar; i++) a*=(n[i]-'0');
        for(int i=bar; i<n.size(); i++) b*=(n[i]-'0');
        if(a==b){isok=1; break;}
    } isok?cout<<"YES":cout<<"NO";
}