#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    int t; cin>>t; string str; cin.ignore();
    while(t--){
        stack <char> st;
        getline(cin, str);
        for(int i=0; i<str.size(); i++){
            if(str[i]==' '){ 
                while (!st.empty()) {
                    cout<<st.top(); st.pop();
                } cout<<' ';
            } else st.push(str[i]);
        } while (!st.empty()) { cout<<st.top(); st.pop();} if(t!=0) cout<<'\n';
    }
}