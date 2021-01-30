#include<iostream>
using namespace std;
int main(){
    int m, r, ans=0; cin>>m; r=1000-m;
    while (0<r){
        if(500<=r) { ans+=r/500; r-=(r/500*500);}
        else if(100<=r) { ans+=r/100; r-=(r/100*100);}
        else if(50<=r) { ans+=r/50; r-=(r/50*50);}
        else if(10<=r) { ans+=r/10; r-=(r/10*10);}
        else if(5<=r) { ans+=r/5; r-=(r/5*5);}
        else { ans+=r; r=0;}
    } cout<<ans;
}