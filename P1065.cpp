#include<iostream>
using namespace std;

int main(){
    int n, a, b, c, ans=0; cin>>n;
    for(int i=1; i<=n; i++){
        if(i<100) ans++;
        else if(i!=1000){ 
            a=i/100; b=(i-a*100)/10; c=i%10;
            if(a-b==b-c) ans++;}
    } cout<<ans;
}