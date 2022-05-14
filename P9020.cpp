#include <iostream>
#include <cstring>
using namespace std;

int T, N, a, b;
int isPrime[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--){
        cin >> N;
        memset(isPrime, 1, sizeof(isPrime));
        a=0; b=0;
        for(int i=2; i*i<=N; i++){
            if(!isPrime[i]) continue;
            for(int j=i*i; j<=N; j+=i) isPrime[j] = false;
        }
        for(int i=2; i<=N/2; i++){
            if(isPrime[i] && isPrime[N-i]){
                a = i;
                b = N-i;
            }
        }
        cout << a << " " << b << "\n";
    }
}