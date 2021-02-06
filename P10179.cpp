#include<iostream>
using namespace std;
int main(){
    int t; double price; cin>>t; cout<<fixed; cout.precision(2);
    while (t--){
        cin>>price; cout<<"$"<<price*0.8<<'\n';
    }
}