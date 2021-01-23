#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    int n, m, a, b, tmp, ans; cin>>n; int num[n+1]={0};
    for(int i=1; i<=n; i++) {
        cin>>tmp; num[i]=num[i-1]+tmp;
    } cin>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b; ans=num[b]-num[a-1]; cout<<ans<<'\n';
    }
}