#include<iostream>
using namespace std;
int main(){
    int n, m, lx, ly, rx, ry, ans=0, paint[101][101]{}; cin>>n>>m;
    while (n--) {
        cin>>lx>>ly>>rx>>ry;
        for(int i=lx; i<=rx; i++){
            for(int j=ly; j<=ry; j++) paint[i][j]++;
        }
    } for(int i=1; i<101; i++){
        for(int j=1; j<101; j++){
            if(m<paint[i][j]) ans++;
        }
    } cout<<ans;
}