#include<iostream>
using namespace std;
int main(){
    int n, ans=0, score[101], num[101]; cin>>n;
    for(int i=1; i<=n; i++) cin>>num[i]; 
    score[1]=num[1]; ans=score[1];
    for(int i=2; i<=n; i++){
        if(num[i]&&num[i-1]) score[i]=score[i-1]+1;
        else score[i]=num[i];
        ans+=score[i];
    } cout<<ans;
}