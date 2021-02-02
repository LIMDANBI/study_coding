#include<iostream>
#include<string>
using namespace std;
int main(){
    int n; cin>>n; string str; getline(cin, str);
    for(int i=0; i<n; i++){
        getline(cin, str); int cnt=0, j;
        for(j=0; j<str.size(); j++){
            if(str.at(j)==' ')cnt++;
            if(cnt==2) break;
        } cout<<str.substr(j+1, str.size())<<" "<<str.substr(0,j)<<'\n';
    }
}