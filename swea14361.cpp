#include<iostream>
#include<string>
#include<vector>
using namespace std;

int num, len;
vector<char> v;
bool flag, check[7];

void make_v(string str){
    v.clear();
    for(int i=0; i<str.size(); i++) {
        v.push_back(str[i]);
        check[i] = false;
    }
}

void backtracking(int cnt, string str){
    if(cnt == len){
        if(str[0] == '0') return;
        int n = stoi(str);
        if(n/num && n%num==0 && n!=num) flag = true;
        return;
    }
    for(int i=0; i<len; i++){
        if(check[i]) continue;
        check[i] = true;
        backtracking(cnt+1, str+v[i]);
        check[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        string str; cin >> str;
        num = stoi(str);
        len = str.size();
        flag = false;
        make_v(str);
        backtracking(0, "");
        if(flag) cout << "#" << t << " possible\n";
        else cout << "#" << t << " impossible\n";
    }
}