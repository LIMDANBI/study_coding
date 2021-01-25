#include<iostream>
using namespace std;
int main(){
    string str=""; int n, m; cin>>n>>m;
    for(int i=0; i<n; i++) str+=to_string(n);
    str.size()<m?cout<<str:cout<<str.substr(0,m);
}