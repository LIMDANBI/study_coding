#include <iostream>
using namespace std;

int map[10];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='6' || s[i]=='9'){
            if(map[6] < map[9]) map[6]++;
            else map[9]++;
        }
        else{
            map[s[i]-'0']++;
        }
    }
    int ans = 0;
    for(int i=0; i<10; i++){
        ans = max(map[i], ans);
    }
    cout << ans;
}