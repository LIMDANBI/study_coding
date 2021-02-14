#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string ring, tmp; cin>>ring; int n, ans=0; cin>>n;
    while (n--){
        cin>>tmp; tmp+=tmp.substr(0, tmp.size()-1);
        if(tmp.find(ring)!=string::npos) ans++;
    } cout<<ans;
}