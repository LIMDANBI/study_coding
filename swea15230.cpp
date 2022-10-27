#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string proper = "abcdefghijklmnopqrstuvwxyz";
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        int ans = 0;
        string str; cin >> str;
        for(int i=0; i<str.size(); i++){
            if(str[i] == proper[i]) ans++;
            else break;
        }
        cout << "#" << t << " " <<  ans << "\n";
    }
}