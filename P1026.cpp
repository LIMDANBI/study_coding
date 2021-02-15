#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, A[51]{}, B[51]{}, ans=0; cin>>n;
    for(int i=0; i<n; i++) cin>>A[i]; sort(A+0, A+n);
    for(int i=0; i<n; i++) cin>>B[i]; sort(B+0, B+n);
    int a=0, b=n-1; while (a!=n){ ans+=A[a]*B[b]; a++; b--;} cout<<ans;
}