#include<iostream>
using namespace std;
int main(){
    int n, k, begin=0, num[21]{}, idx=0; cin>>n>>k; string sequence; cin>>sequence;
    for (int i=0; i<sequence.size(); i++){
        if(sequence[i]==',') { 
            num[idx]=stoi(sequence.substr(begin, i)); 
            idx++; begin=i+1;
        }
    } num[idx]=stoi(sequence.substr(begin, sequence.size()));  int tmp=n-1; 
    while (k--) {
        for(int i=0; i<tmp; i++) num[i] = num[i+1]-num[i];
        tmp--;
    } for(int i=0; i<tmp+1; i++) { 
        cout<<num[i]; if(i!=tmp) cout<<",";
    }
}