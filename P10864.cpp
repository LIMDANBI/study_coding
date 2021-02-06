#include<iostream>
using namespace std;
int main(){
    int n, m, a, b, f[1001]{}; cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a>>b; f[a]++; f[b]++;
    }
    for(int i=1; i<=n; i++) cout<<f[i]<<'\n';
}