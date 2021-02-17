#include<iostream>
using namespace std;
int main(){
    string str; getline(cin, str); int idx=0;
    while (idx<str.size()){ cout<<str[idx];
        if(str[idx]=='a' || str[idx]=='e' || str[idx]=='i' || str[idx]=='o' || str[idx]=='u')  idx+=3;
        else idx++;
    }
}