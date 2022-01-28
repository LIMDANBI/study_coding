#include<iostream>
#define MAX_N 101
#define MAX_C 10001 // maximum total cost
using namespace std;

int N, M, total_cost, ans;
int memory[MAX_N], cost[MAX_N];
int DP[MAX_C]; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> memory[i]; // 현재 활성화 되어 있는 앱의 메모리 바이트 수
    for(int i=1; i<=N; i++) {
        cin >> cost[i]; // 각 앱을 비활성화 했을 경우 비용 
        total_cost+=cost[i];
    }
    for(int i=1; i<=N; i++){
        for(int j=total_cost; j>=cost[i]; j--){
            DP[j] = max(DP[j], DP[j-cost[i]]+memory[i]); // j 비용으로 확보할 수 있는 최대 메모리 => max(i 번째 앱을 비활성화 했을 경우 , i 번째 앱을 활성화했을 경우)
        }
    }
    for(int j=1; j<=total_cost; j++){
        if(M<=DP[j]){ // 처음으로 메모리가 M 이상인 곳을 찾음
            cout << j; // 비용 출력 
            break;
        }
    }
}