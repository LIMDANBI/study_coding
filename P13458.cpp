#include<iostream>
using namespace std;

int N, B, C;
int A[1000001];

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    cin >> B >> C;
}

void solution(){
    long long ans = N;
    for(int i=0; i<N; i++){
        int res = max(A[i]-B, 0);
        ans+=(res/C);
        if(res%C) ans++;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}