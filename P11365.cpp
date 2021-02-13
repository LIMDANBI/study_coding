#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str; stack<char> code;
    while (1){
        getline(cin, str);
        if(str=="END") break;
        else{ for(int i=0; i<str.size(); i++) code.push(str[i]);}
        while(!code.empty()){cout<<code.top(); code.pop();} cout<<'\n';
    }
}