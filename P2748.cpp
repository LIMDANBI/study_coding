#include<iostream>
using namespace std;
int main(){
    int n; cin>>n; long long fibo[91]={0,1,1};
    for(int i=3; i<=90; i++) fibo[i]=fibo[i-1]+fibo[i-2]; cout<<fibo[n];
}