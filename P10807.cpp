#include <iostream>
using namespace std;
 
int main(){
    int n, v, ans=0; cin >>n; int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i]; cin>>v;
    for(int i=0; i<n; i++){if(arr[i]==v) ans++;}
    cout<<ans;
}