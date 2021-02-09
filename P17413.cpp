#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> st; string str; getline(cin,str); int whole=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='<') {
            while (!st.empty()){ char tmp=st.top(); cout<<tmp; st.pop();}
            cout<<str[i]; whole=1;}
        else if(str[i]=='>') {cout<<str[i]; whole=0;}
        else{
            if(whole) cout<<str[i];
            else{
                if(str[i]==' ') {
                    while (!st.empty()){
                        char tmp=st.top(); cout<<tmp; st.pop();
                    } cout<<' ';
                } else st.push(str[i]);}
        }
    } while (!st.empty()){ char tmp=st.top(); cout<<tmp; st.pop();} 
}