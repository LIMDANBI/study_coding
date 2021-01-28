#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, max=0; cin>>n;
    for(int i=0; i<n; i++){
        int a,b,c,d,tmp; cin>>a>>b>>c>>d;
        if(a==b&&b==c&&c==d) tmp=50000+a*5000;
        else if(a==b&&b==c || a==c&&c==d) tmp=10000+a*1000;
        else if(b==c&&c==d || a==b&&b==d) tmp=10000+b*1000;
        else if(a==b&&c==d) tmp=2000+a*500+c*500;
        else if(a==c&&b==d || a==d&&b==c) tmp=2000+a*500+b*500;
        else if(a==b || a==c || a==d) tmp=1000+a*100;
        else if(b==c || b==d) tmp=1000+b*100;
        else if(c==d) tmp=1000+c*100;
        else{
            int increase[4]={a,b,c,d}; sort(increase+0, increase+4);
            tmp=increase[3]*100;
        }
        if(max<tmp) max=tmp;
    } cout<<max;
}