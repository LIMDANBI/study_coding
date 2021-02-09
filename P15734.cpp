#include<iostream>
using namespace std;
int main(){
    int l, r, a; cin>>l>>r>>a;
    if(l==r){a%2?cout<<l+r+a-1:cout<<l+r+a;} 
    else if(l<r){
        if(l+a<r) cout<<(l+a)*2;
        else (a-r+l)%2?cout<<r*2+a-r+l-1:cout<<r*2+a-r+l;
    }
    else{
        if(r+a<l) cout<<(r+a)*2;
        else (a-l+r)%2?cout<<l*2+a-l+r-1:cout<<l*2+a-l+r;
    }
}