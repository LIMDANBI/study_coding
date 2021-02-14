#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    while (n--){
        int alphabet[26]{}, isok=1;
        string str1, str2; cin>>str1>>str2;
        for(int i=0; i<str1.size(); i++) alphabet[str1[i]-97]++;
        for(int i=0; i<str2.size(); i++) alphabet[str2[i]-97]--;
        for(int i=0; i<26; i++){
            if(alphabet[i]!=0) {isok=0; break;}
        } isok?cout<<"Possible":cout<<"Impossible"; cout<<'\n';
    }
}