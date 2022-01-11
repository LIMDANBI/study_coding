#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int n; cin>>n;
    int tri[n+1][n+1]={};
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>tri[i][j];
        }
    }
    for(int i=n-2; -1<i; i--){
        for(int j=0; j<i+1; j++){
            tri[i][j] = tri[i][j]+max(tri[i+1][j], tri[i+1][j+1]);
        }
    }
    cout << tri[0][0];
}