#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a, b, c, n, tmp; cin>>a>>b>>c>>n; tmp=n/min(a, min(b,c));
    if(n%a==0 || n%b==0 || n%c==0) cout<<1;
    else{
        int isok=0;
        for(int i=0; i<=tmp; i++){
            for(int j=0; j<=tmp; j++){
                for(int k=0; k<=tmp; k++){ if(a*i+b*j+c*k==n) isok=1;}
            }
        } isok?cout<<1:cout<<0;
    }
}