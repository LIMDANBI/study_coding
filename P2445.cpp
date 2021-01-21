#include <iostream>
using namespace std;

int main(){
    int n; cin >>n;
    for(int i=0; i<2*n-1; i++){
        if(i<n){
            for(int j=0; j<2*n; j++){
                if(i+1>j || 2*n-i-2<j) cout << "*";
                else cout << " ";
            } cout <<'\n';
        }
        else{
            for(int j=0; j<2*n; j++){
                if(2*n-i-2<j && j<i+1) cout << " ";
                else cout << "*";
            } cout <<'\n';
        }
    }
}