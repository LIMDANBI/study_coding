#include <iostream>
using namespace std;

int main(){
    int n, a, b, ans=0, colorpaper[101][101]={0,}; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        for(int j=a; j<a+10; j++){
            for(int k=b; k<b+10; k++) colorpaper[j][k]++;
        }
    }
    for(int i=1; i<101; i++){
        for(int j=1; j<101; j++){ if(colorpaper[i][j]) ans++;}
    }
    cout << ans;
}