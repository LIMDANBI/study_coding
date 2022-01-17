#include<iostream>
#define MAX 301
using namespace std;

int N;
int score[MAX], dp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // 입력
    cin>>N; 
    for(int i=1; i<=N; i++) cin>>score[i];
    
    // 초기화
    dp[1] = score[1];
    dp[2] = max(score[2], score[1]+score[2]);
    dp[3] = max(score[1]+score[3], score[2]+score[3]);

    // dynamic programming
    for(int i=4; i<=N; i++)
        dp[i] = max(score[i]+dp[i-2] , score[i]+score[i-1]+dp[i-3]);
    
    // 정답 출력
    cout << dp[N];
}