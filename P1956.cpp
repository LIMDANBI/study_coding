#include<iostream>
#define INF 987654321
#define MAX 401
using namespace std;

int V, E, A, B, C, ans=INF;
int cost[MAX][MAX];

void floyd(){
    for(int k=1; k<=V; k++){ // floyd-warshall 알고리즘
        for(int a=1; a<=V; a++){
            for(int b=1; b<=V; b++){
                cost[a][b] = min(cost[a][b], cost[a][k]+cost[k][b]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=1; i<=V; i++){ // 초기화
        for(int j=1; j<=V; j++) cost[i][j] = INF;
    }
    for(int i=0; i<E; i++){
        cin >> A >> B >> C;
        cost[A][B] = min(cost[A][B], C);
    }
    floyd();
    for(int i=1; i<=V; i++) ans = min(ans, cost[i][i]);
    ans == INF ? cout << -1 : cout << ans;
}