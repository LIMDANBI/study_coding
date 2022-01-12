#include<iostream>
#define INF 987654321
#define MAX_N 501
using namespace std;

int N, M, a, b; 
int cost[MAX_N][MAX_N]={};

void floyd(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cost[i][j] = INF;
    }
    for(int i=0; i<M; i++){
        cin>>a>>b; cost[a][b]=1;
    }
    floyd();
    int ans=0;
    for(int i=1; i<=N; i++){
        int cnt=0;
        for(int j=1; j<=N; j++){
            if(cost[i][j]!=INF || cost[j][i]!=INF) cnt++;
        }
        if(cnt==N-1) ans++;
    }
    cout << ans;
}