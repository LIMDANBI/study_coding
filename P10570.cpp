#include<iostream>
using namespace std;
int main(){
    int n, v, s; cin>>n;
    while (n--){
        int num[1001]{}, max=0, ans; cin>>v;
        for(int i=0; i<v; i++){cin>>s; num[s]++;}
        for(int i=1; i<=1000; i++){
            if(max<num[i]) {max=num[i]; ans=i;}
        } cout<<ans<<'\n';
    }   
}