#include<iostream>
#define MAX_N 21
#define MAX_P 100
using namespace std;

int N;
int L[MAX_N], J[MAX_N];
int DP[MAX_N][MAX_P];

void input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> L[i];
    for(int i=1; i<=N; i++) cin >> J[i];
}

void solution(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=MAX_P; j++){
            if(L[i] >= j) DP[i][j] = DP[i-1][j];
            else DP[i][j] = max(DP[i-1][j], DP[i-1][j-L[i]]+J[i]);
        }
    }
    cout << DP[N][MAX_P];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}