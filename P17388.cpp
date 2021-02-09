#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int s, k, h; cin>>s>>k>>h;
    if(100<=s+k+h) cout<<"OK";
    else{
        int tmp = min(min(s,k),h);
        if(tmp==s) cout<<"Soongsil";
        else if(tmp==k) cout<<"Korea";
        else cout<<"Hanyang";
    }
}