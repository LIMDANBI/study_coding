#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; cin.ignore();
    while(N--){
        string str;
        getline(cin, str);
        if(96<str[0]) str[0]-=32;
        cout << str << '\n';
    }
}