#include<iostream>
using namespace std;
int main(){
    int r, c, a, b; char piece[101][101]{}; cin>>r>>c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++) {
            cin>>piece[i][j]; piece[i][c*2-j+1]=piece[i][j];
            piece[r*2-i+1][j]=piece[i][j]; piece[r*2-i+1][c*2-j+1]=piece[i][j];
        }
    } cin>>a>>b;
    for(int i=1; i<=r*2; i++){
        for(int j=1; j<=c*2; j++) {
            if(i==a && j==b) piece[i][j]=='#'?cout<<'.': cout<<'#';
            else cout<<piece[i][j]; 
        } cout<<'\n';
    }
}