#include<iostream>
using namespace std;
int main(){
    int x, y, rx=0, ry=0, rsum; cin>>x>>y;
    if(x==1000||x==100||x==10||x==1) rx=1;
    else{
        if(100<x&&x<1000) rx=x%10*100+(x%100)/10*10+x/100;
        else if(10<x&&x<100) rx=(x%10)*10+x/10;
        else rx=x;
    }
    if(y==1000||y==100||y==10||y==1) ry=1;
    else{
        if(100<y&&y<1000) ry=y%10*100+(y%100)/10*10+y/100;
        else if(10<y&&y<100) ry=(y%10)*10+y/10;
        else ry=y;
    } rsum=rx+ry;
    if(1000<=rsum&&rsum<=2000) cout<<(rsum%10)*1000+(rsum%1000)%100/10*100+(rsum%1000)/100*10+rsum/1000;
    else if(100<=rsum&&rsum<1000) cout<<rsum%10*100+(rsum%100)/10*10+rsum/100;
    else if(10<=rsum&&rsum<100) cout<<(rsum%10)*10+rsum/10;
    else cout<<rsum;
}