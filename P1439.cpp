#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    char prev = s[0]; // 이전 연속되는 문자
    int zero=0, one=0; // 연속되는 0, 1 개수
    for(int i=1; i<s.length(); i++){
        if(s[i]!=prev){ // 문자가 바뀐 경우
            if(prev == '0') zero++;
            else one++;
            prev = s[i];
        }
        if(i==s.length()-1){
            if(s[i] == '0') zero++;
            else one++;
        }
    }
    cout << min(zero, one);
}