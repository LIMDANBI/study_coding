#include<iostream>
using namespace std;
int main(){
    int n, k, num[1001]{}, ans=0, idx=2; cin>>n>>k;
    while (ans==0){
        for(int i=1; idx*i<=n; i++){
            if(num[idx*i]==0) { num[idx*i]++; k--;}
            if(k==0) {ans=idx*i; break;}
        } idx++; 
    } cout<<ans;
}