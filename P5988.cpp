#include<iostream>
#include <string.h>
using namespace std;

int main(){
    int n, last; cin>>n; string num;
    for(int i=0; i<n; i++){
        cin>>num; last=num.at(num.size()-1)-48;
        if(last%2==0) cout<<"even"<<'\n';
        else cout<<"odd"<<'\n';
    }
}