#include<iostream>
using namespace std;
int main(){
    int drop, ride, train[11]{}, max=-1;
    for(int i=1; i<=10; i++){
        cin>>drop>>ride; train[i]=train[i-1]-drop+ride;
        if(max<train[i]) max=train[i];
    } cout<<max;
}