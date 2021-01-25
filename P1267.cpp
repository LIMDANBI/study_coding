#include<iostream>
using namespace std;
int main(){
    int n, tmp, y=0, m=0; cin>>n; 
    for(int i=0; i<n; i++){
        cin>>tmp; y+=(tmp/30+1); m+=(tmp/60+1);
    }
    if(y*10==m*15) cout<<"Y "<<"M "<<y*10;
    else{ y*10<m*15?cout<<"Y "<<y*10:cout<<"M "<<m*15; }
}