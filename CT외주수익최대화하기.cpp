#include<iostream>
#define MAX 16
using namespace std;

int n;
int arr[MAX][2], dp[MAX];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i][0] >> arr[i][1]; //  외주 작업의 기한, 수익
}

void solution(){ // 가능한 외주 수익의 최대값
    for(int day=n; day>0; day--){
        int deadline = day+arr[day][0];
        if(n+1<deadline) dp[day] = dp[day+1]; // 외주 불가능 
        else dp[day] =  max(dp[day+1], dp[deadline]+arr[day][1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << dp[1];
}