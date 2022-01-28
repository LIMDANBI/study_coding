#include<iostream>
#include<cstring>
#define MAX 16
#define INF 98765432
using namespace std;

int N;
int W[MAX][MAX], DP[MAX][1<<MAX]; //  순회를 마치는데 드는 최소비용 저장

int TSP(int current, int visited){
    if(visited == (1<<N)-1){ // 모든 도시를 방문한 경우 (0 ~ N-1 비트가 켜져있음)
        if(W[current][0] == 0) return INF; // 다시 출발지로 돌아갈 수 없는 경우
        return W[current][0]; // 출발지로 돌아갈 수 있는 경우
    }
    int &ans = DP[current][visited]; // 메모이제이션
    if(ans != -1) return ans; // 이미 값이 있는 경우 
    ans = INF;
    for(int next=1; next<N; next++){
        if(visited & (1<<next) || W[current][next]==0) continue; // 이미 방문했거나, 현재 도시에서 도시 i로 가는 길이 없는 경우
        ans = min(ans, W[current][next]+TSP(next, visited|(1<<next)));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> W[i][j];
    }
    memset(DP, -1, sizeof(DP));
    cout << TSP(0, 1); // 0번 도시에서 출발
}