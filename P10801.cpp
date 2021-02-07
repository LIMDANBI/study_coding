#include<iostream>
using namespace std;
int main(){
    int a[10]{}, b[10]{}, A=0, B=0;
    for(int i=0; i<10; i++) cin>>a[i];
    for(int i=0; i<10; i++) {
        cin>>b[i];
        if(a[i]<b[i]) B++; else if(a[i]>b[i]) A++;
    }
    if(A<B) cout<<"B";
    else if(A==B) cout<<"D";
    else cout<<"A";
}