#include<iostream>
using namespace std;
int main(){
    int len, t=0, e=0; cin>>len; char tmp;
    while (len--){
        cin>>tmp; tmp=='e'?e++:t++;
    } if(e==t) cout<<"yee"; else if(t<e) cout<<"e"; else cout<<2;
}