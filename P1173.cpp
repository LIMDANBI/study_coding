#include<iostream>
using namespace std;
int main(){
    int N, m, M, T, R, ans=0, ex=0, X; cin>>N>>m>>M>>T>>R; X=m;
    while (N!=ex){ ans++;
        if(X+T<=M){X+=T; ex++;}
        else {X-=R; if(X<m) X=m;}
        if(X+T>M && X==m) {cout<<-1; return 0;}
    } cout<<ans;
}