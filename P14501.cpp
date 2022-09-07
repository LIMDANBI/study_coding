#include<iostream>
#define MAX 16
using namespace std;

int N, t, p;
int arr[MAX][2], dp[MAX];

void input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i][0] >> arr[i][1];
}

void solution(){
    for(int day=N; day>0; day--){
        int deadline = day+arr[day][0];
        if(N+1 < deadline) dp[day] = dp[day+1]; // 상담 불가능
        else dp[day] = max(dp[day+1], dp[deadline]+arr[day][1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << dp[1];
}