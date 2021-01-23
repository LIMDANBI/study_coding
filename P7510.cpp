#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, len[3]; cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) cin>>len[j]; sort(len+0, len+3);
        if(len[0]*len[0]+len[1]*len[1] == len[2]*len[2]) cout<<"Scenario #"<<i+1<<":"<<'\n'<<"yes"<<'\n';
        else cout<<"Scenario #"<<i+1<<":"<<'\n'<<"no"<<'\n'; if(i!=n-1) cout<<'\n';
    }
}