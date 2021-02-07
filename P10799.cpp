#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int ans=0; stack<int> st;
    string ironBar; cin>>ironBar;
    for(int i=0; i<ironBar.size(); i++){
        if(ironBar[i]=='(') st.push(ironBar[i]);
        else { 
            if(ironBar[i-1]=='(') {st.pop(); ans+=st.size();}
            else {st.pop(); ans++;}
        }
    } cout<<ans;
}