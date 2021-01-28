#include<iostream>
using namespace std;
int main(){
    int t, n; cin>>t;
    for(int i=0; i<t; i++){
        cin>>n; long long num[100001]; int ans=0;
        for(int j=0; j<n; j++) {cin>>num[j]; num[j]%=n; ans+=num[j];}
        if(ans%n==0) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}