#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin>>n>>m;
    int arr[10001]={};
    for(int i=0; i<n; i++) cin>>arr[i];
    
    int low=0, high=0, sum=0, ans=0;
    while(1){
        if(m<=sum) sum-=arr[low++];
        else if(high==n) break;
        else sum+=arr[high++];
        if(sum==m) ans++;
    }
    cout<<ans;
}