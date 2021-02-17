#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int num[3]{}; string str; cin>>num[0]>>num[1]>>num[2]>>str; sort(num+0, num+3);
    for(int i=0; i<str.size(); i++){
        if(str[i]=='A') cout<<num[0]<<" ";
        else if(str[i]=='B') cout<<num[1]<<" ";
        else cout<<num[2]<<" ";
    }
}