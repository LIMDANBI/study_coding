#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i=0; i<2*n-1; i++){
        if(i<n){
            for(int j=0; j<n+i; j++){
                if(j<n-i-1) cout << " ";
                else cout << "*";
            } cout<<'\n';
        }
        else{
            for(int j=0; j<3*n-i-2; j++){
                if(j<i-n+1) cout << " ";
                else cout << "*";
            } cout<<'\n';
        }
    }
}