#include<iostream>
using namespace std;
int main(){
    string str; getline(cin, str); char output, small, big;
    for(int i=0; i<str.size(); i++){ output=str[i]+13, small=output-'z'+'a'-1, big=output-'Z'+'A'-1; 
        if('a'<=str[i]&&str[i]<='z'){
            if(str[i]+13<='z') cout<<output;
            else cout<<small;
        } else if('A'<=str[i]&&str[i]<='Z'){
            if(str[i]+13<='Z') cout<<output;
            else cout<<big;
        } else cout<<str[i];
    }
}