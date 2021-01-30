#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t[3];
    while (1){
        cin>>t[0]>>t[1]>>t[2];
        if(t[0]==0&&t[1]==0&&t[2]==0) break;
        else{ 
            sort(t+0, t+3);
            if(t[2]*t[2]==t[0]*t[0]+t[1]*t[1]) cout<<"right"<<'\n';
            else cout<<"wrong"<<'\n';
        }
    }
}