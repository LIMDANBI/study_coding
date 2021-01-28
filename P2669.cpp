#include<iostream>
using namespace std;
int main(){
    int area[101][101]{}, ans=0;
    for(int i=0; i<4; i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        for(int j=a; j<c; j++){
            for(int k=b; k<d; k++) area[j][k]=1;
        }
    }
    for(int i=1; i<101; i++){
        for(int j=1; j<101; j++) ans+=area[i][j];
    } cout<<ans;
}