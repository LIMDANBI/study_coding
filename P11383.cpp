#include<iostream>
using namespace std;
int main(){
    int n, m, isEyfa=1; char image[11][11]{}, image2[22][22]{}; cin>>n>>m;
    for(int i=0; i<n; i++){ for(int j=0; j<m; j++) cin>>image[i][j];}
    for(int i=0; i<n; i++){ for(int j=0; j<m*2; j++) cin>>image2[i][j];}
    for(int i=0; i<n; i++){ 
        for(int j=0; j<m; j++){
            if(image[i][j]!=image2[i][j*2] || image[i][j]!=image2[i][j*2+1]) isEyfa=0;
        }
    } isEyfa?cout<<"Eyfa":cout<<"Not Eyfa";
}