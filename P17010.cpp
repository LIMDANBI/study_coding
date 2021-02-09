#include<iostream>
using namespace std;
int main(){
    int n, l; string m; cin>>n;
    while (n--){
        cin>>l>>m;
        while (l--) cout<<m; cout<<'\n';
    }
}