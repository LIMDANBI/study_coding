#include<iostream>
using namespace std;
int main(){
    int a,b,c, time[101]{}, fee=0; cin>>a>>b>>c;
    for(int i=0; i<3; i++){
        int n, m; cin>>n>>m; for(int j=n; j<m; j++) time[j]++;
    } for(int i=0; i<=100; i++){
        if(time[i]==1) fee+=a;
        else if(time[i]==2) fee+=b*2;
        else if(time[i]==3) fee+=c*3;
    } cout<<fee;
}