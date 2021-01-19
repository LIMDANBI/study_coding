#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int N, ans=0; cin >> N;
    for(int i=0; i<N; i++){
        string tmp; cin >> tmp; 
        int isgroup=1, alphbet[26]={0,}; alphbet[tmp.at(0)-97]++;
        for(int j=1; j<tmp.size(); j++){
            if(alphbet[tmp.at(j)-97]!=0 && tmp.at(j-1)!=tmp.at(j)) isgroup=0;
            alphbet[tmp.at(j)-97]++;
        }
        if(isgroup) ans++;
    } 
    cout << ans;
}