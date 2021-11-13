#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, m; cin>>n>>m;
    int sums[n+1] = {};
    for(int i=1; i<=n; i++){
        int tmp; cin>>tmp;
        sums[i] = sums[i-1]+tmp;
    }
    for(int k=0; k<m; k++){
        int i, j; cin>>i>>j;
        cout << sums[j]-sums[i-1] << '\n';
    }  
}