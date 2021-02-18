#include<iostream>
using namespace std;
int main(){
    int t; cin>>t; string s;
    while (t--){
        cin>>s; int alphabet[26]{}, ans=0;
        for(int i=0; i<s.size(); i++) alphabet[s[i]-65]++;
        for(int i=0; i<26; i++){
            if(alphabet[i]==0) ans+=(i+65);
        } cout<<ans<<'\n';
    }
}