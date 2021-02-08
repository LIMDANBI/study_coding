#include<iostream>
using namespace std;
int main(){
    int card[21]; for(int i=0; i<=20; i++) card[i]=i;
    for(int i=0; i<10; i++){
        int a, b, idx=0; cin>>a>>b;
        for(int j=a; j<a+(b-a+1)/2; j++){
            int tmp=card[a+idx];
            card[a+idx]=card[b-idx];
            card[b-idx]=tmp; idx++; }
    } for(int i=1; i<=20; i++) cout<<card[i]<<" ";
}