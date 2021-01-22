#include <iostream>
using namespace std;

int main(){
    char tmp;int ans=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){ cin>>tmp; if((i+j)%2==0 && tmp=='F') ans++;}
    } cout << ans;
}