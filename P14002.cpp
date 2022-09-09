#include<iostream>
#include<vector>
#define MAX 1001
using namespace std;

int N, len=0;
int A[MAX], dp[MAX];
vector<int> sequence;

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
}

void solution(){
    for(int i=0; i<N; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(A[i]>A[j]) dp[i] = max(dp[j]+1, dp[i]);
        }
        len = max(dp[i], len);
    }
    for(int i=N-1; i>=0; i--){
        if(dp[i] == len){
            sequence.push_back(A[i]);
            len--;
        }
    }
}

void output(){
    cout << sequence.size() << "\n";
    while (sequence.size()){
        cout << sequence.back() << " ";
        sequence.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}