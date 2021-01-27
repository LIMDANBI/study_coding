#include<iostream>
using namespace std;
int main(){
    int h, p; 
    while(scanf("%d %d",&h,&p) != EOF){
        cout<<fixed; cout.precision(2); cout<<h/(double)p<<'\n';
    }
}