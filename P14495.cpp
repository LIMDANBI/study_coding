#include<iostream>
using namespace std;
int main(){
    int n; cin>>n; long long likefibo[n+1];
    for(int i=1; i<=n; i++){
        if(i<4) likefibo[i]=1;
        else likefibo[i]=likefibo[i-1]+likefibo[i-3];
    } cout<<likefibo[n];
}