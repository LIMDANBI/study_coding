#include <iostream>
#include <cstring>
#define MAX 246915
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    bool isPrime[MAX];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for(int i=2; i*i<MAX; i++){ // 에라토스테네스의 체
        if(!isPrime[i]) continue; //이미 소수가 아니라고 chekck 한 경우
        for(int j=i*i; j<MAX; j+=i) isPrime[j] = false;
    }
    while(1){
        int n, ans=0; 
        cin >> n;
        if(n==0) break;
        for(int i=n+1; i<=2*n; i++){
            if(isPrime[i]) ans++;
        }
        cout << ans << "\n";
    }
}