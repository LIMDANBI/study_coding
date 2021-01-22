#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int W[10], K[10], scoreW, scoreK;
    for(int i=0; i<10; i++) cin>>W[i]; sort(W,W+10); scoreW+=(W[9]+W[8]+W[7]);
    for(int i=0; i<10; i++) cin>>K[i]; sort(K, K+10); scoreK+=(K[9]+K[8]+K[7]);
    cout<<scoreW<<" "<<scoreK;
}