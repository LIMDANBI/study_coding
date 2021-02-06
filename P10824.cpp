#include<iostream>
#include<string>
using namespace std;
int main(){
    string a, b, c, d, ab, cd; cin>>a>>b>>c>>d; ab=a+b; cd=c+d;
    long long ans=std::stoll(ab)+std::stoll(cd); cout << ans;
}