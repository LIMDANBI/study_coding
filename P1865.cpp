#include <iostream>
#include <vector>
#define INF 2100000000
#define MAX 501
using namespace std;

struct DATA{int end, cost;};
vector<DATA> G[MAX];

int TC, N, M, W, s, e, t;
int dist[MAX];

void init(){ // 초기화
    for(int i=1; i<=N; i++) {
        dist[i] = INF;
        G[i].clear();
    }
}

void bellmanFord(){
    dist[1] = 0;
    bool cycle = false;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<G[j].size(); k++){
                int next_node = G[j][k].end;
                int next_cost = G[j][k].cost;
                if(dist[j]!=INF && dist[j]+next_cost<dist[next_node]){
                    dist[next_node] = dist[j]+next_cost;
                    if(i==N) cycle = true;
                }
            }
        }
    }
    if(cycle) cout << "NO\n";
    else cout << "YES\n"; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> TC;
    while (TC--){
        cin >> N >> M >> W;
        init();
        for(int i=0; i<M; i++){ // 도로 정보
            cin >> s >> e >> t;
            G[s].push_back({e, t});
            G[e].push_back({s, t}); // 도로는 방향이 없으며
        }
        for(int i=0; i<M; i++){ // 웜홀 정보
            cin >> s >> e >> t;
            G[s].push_back({e, -t}); // 웜홀은 방향이 존재
        }
        bellmanFord();
    }
}