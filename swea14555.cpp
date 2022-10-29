#include<iostream>
#include<stack>
using namespace std;

int solution(string str){
    int res = 0;
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='(') s.push(str[i]);
        else if(str[i]==')'){
            if(!s.empty()){
                res++;
                s.pop();
            }
        }
        else if(str[i]=='|'){
            if(s.empty()) s.push(str[i]);
            else if(s.top()=='('){
                res++;
                s.pop();
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        string S; cin >> S;
        cout << "#" << t << " " << solution(S) << "\n";
    }
}