#include<iostream>
#define MAX 11
using namespace std;

int n, k, coin[MAX];

void input(){
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> coin[i];
}

void solution(){
    int ans = 0;
    int select_coin = n-1;
    for(int i=n-1; i>=0; i--){
        ans+=k/coin[i];
        k%=coin[i];
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}