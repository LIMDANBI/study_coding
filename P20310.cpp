#include<iostream>
#define MAX 501
using namespace std;

bool isremove[MAX] = {false};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int zero_cnt=0, one_cnt=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0') zero_cnt++;
        else one_cnt++;
    }
    zero_cnt/=2;
    one_cnt/=2;
    
    int idx = s.size()-1;
    while(zero_cnt){
        if(s[idx]=='0') {
            zero_cnt--;
            isremove[idx] = true;
        }
        idx--;
    }

    idx = 0;
    while(one_cnt){
        if(s[idx]=='1') {
            one_cnt--;
            isremove[idx] = true;
        }
        idx++;
    }

    for(int i=0; i<s.size(); i++){
        if(!isremove[i]) cout << s[i];
    }
}