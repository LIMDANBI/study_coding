#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n, alphabet[26]{}; string str; cin>>n>>str; stack<double> st;
    for(int i=0; i<n; i++) cin>>alphabet[i];
    for(int i=0; i<str.size(); i++){
        if(str[i]=='*'||str[i]=='/'){
            double b=st.top(); st.pop(); double a=st.top(); st.pop();
            if(str[i]=='*') st.push(a*b); else st.push(a/b);
        } else if(str[i]=='+'||str[i]=='-'){
            double b=st.top(); st.pop(); double a=st.top(); st.pop();
            if(str[i]=='+') st.push(a+b); else st.push(a-b);
        } else st.push(alphabet[str[i]-65]);
    } cout<<fixed; cout.precision(2); double ans=st.top(); cout<<ans;
}