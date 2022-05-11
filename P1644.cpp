#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;
vector<bool> isPrime;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    isPrime.resize(N+1, true);

    for(int i=2; i*i<=N; i++){ // 에라토스테네스의 체
        if(!isPrime[i]) continue;
        for(int j=i*i; j<=N; j+=i) isPrime[j] = false;
    }
    for(int i=2; i<=N; i++){
        if(isPrime[i]) prime.push_back(i);
    }

    int start=0, end=0, sum=0, ans=0;
    while (1){ // 투 포인터를 이용하여 소수의 연속합을 찾음
        if(N<=sum) sum-=prime[start++];
        else if(end==prime.size()) break; // N보다 작은 소수를 다 본 경우 
        else sum+=prime[end++];
        if(sum==N) ans++;
    }
    cout << ans;
}