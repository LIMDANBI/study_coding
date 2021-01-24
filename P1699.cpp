#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n; cin>>n; int cnt[100001];
    for(int i=1; i<=n; i++){ 
        cnt[i]=i;
        for(int j=1; j<=sqrt(i); j++){
            cnt[i]=min(cnt[i], cnt[i-j*j]+1);
        }
    } cout<<cnt[n]; 
}