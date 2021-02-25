#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, arr[100001]{}; cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i]; sort(arr+0, arr+n);
    for(int i=0; i<n; i++){
        if(i==0 || arr[i]!=arr[i-1]) cout<<arr[i]<<" ";
    }
}