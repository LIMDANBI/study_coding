#include<iostream>
#include<string>
using namespace std;
int main(){
    int t; cin>>t; cin.ignore();
    for(int i=1; i<=t; i++){
        string str; getline(cin, str); int x, y, z, idx=0;
        while (str[idx]!=' ') idx++; x=std::stoi(str.substr(0, idx));
        idx++; char sign=str[idx]; idx+=2; int start=idx;
        while (str[idx]!=' ') idx++; y=std::stoi(str.substr(start, idx));
        idx+=3; z=std::stoi(str.substr(idx, str.size()));
        if(sign=='+'){
            cout<<"Case "<<i<<": ";
            x+y==z?cout<<"YES"<<'\n':cout<<"NO"<<'\n'; }
        else{
            cout<<"Case "<<i<<": ";
            x-y==z?cout<<"YES"<<'\n':cout<<"NO"<<'\n';}
    }
}