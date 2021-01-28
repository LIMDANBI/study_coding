#include<iostream>
using namespace std;
int main(){
    int t, c, q, d, n, p; cin>>t;
    for(int i=0; i<t; i++){
        cin>>c; q=c/25; c-=25*q; d=c/10; c-=10*d; n=c/5; c-=5*n; p=c;
        cout<<q<<" "<<d<<" "<<n<<" "<<p<<'\n'; 
    }
}