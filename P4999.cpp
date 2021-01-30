#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1, str2; cin>>str1>>str2;
    str1.find("h")<str2.find("h")?cout<<"no":cout<<"go";
}