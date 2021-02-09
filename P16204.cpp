#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, m, k; cin>>n>>m>>k; cout<<min(k, m)+min(n-k, n-m);
}