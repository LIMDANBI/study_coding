#include<iostream>
using namespace std;
int main(){
    int r,c,a,b; cin>>r>>c>>a>>b;
    for(int i=1; i<=r*a; i++){
        for(int j=1; j<=c*b; j++){
            if(0<i%(2*a)&&i%(2*a)<=a){
                if(0<j%(2*b)&&j%(2*b)<=b) cout<<'X'; else cout<<'.';
            } else{
                if(0<j%(2*b)&&j%(2*b)<=b) cout<<'.'; else cout<<'X';
            }
        } cout<<'\n';
    }
}