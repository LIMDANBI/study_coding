#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b, idxA=0, idxB=0, duplicate=0;; cin>>a>>b;
    int A[a]={0,}, B[b]={0,};
    for(int i=0; i<a; i++) cin>>A[i]; sort(A+0,A+a); 
    for(int i=0; i<b; i++) cin>>B[i]; sort(B+0,B+b);
    while(idxA<a&&idxB<b){
        if(A[idxA]==B[idxB]){idxA++; idxB++; duplicate++;}
        else{ A[idxA]<B[idxB]?idxA++:idxB++;}
    } cout<<a+b-2*duplicate;
}