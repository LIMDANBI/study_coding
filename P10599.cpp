#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int a,b,c,d;
    while (1){
        cin>>a>>b>>c>>d;
        if(!a&&!b&&!c&&!d) break;
        else cout<<abs(c-b)<<" "<< abs(d-a)<<'\n';
    }
}