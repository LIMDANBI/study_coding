#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, num[10001]; cin>>n; long long ans=0;
    for(int i=1; i<=n; i++) cin>>num[i]; sort(num+1, num+n+1);
    for(int i=n; 0<i; i--){
        for(int j=1; j<i; j++) ans+=num[i]-num[j];
    } cout<<ans*2;
}