#include <iostream>
#include <vector>
#define INF 2100000000
#define MAX 501
using namespace std;

struct DATA{int start, end, cost;};
vector<DATA> G;

int TC, N, M, W, s, e, t;
int dist[MAX];

void init(){ // 초기화
    for(int i=1; i<=N; i++) dist[i] = INF;
    G.clear();
}

void bellmanFord(){
    dist[1] = 0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<G.size(); j++){
            int start = G[j].start;
            int end = G[j].end;
            int cost = G[j].cost;
            // if(dist[start]==INF) continue;
            if(dist[start]+cost < dist[end]) {
                if(i==N) {
                    cout << "YES\n"; 
                    return ; 
                }
                dist[end] = dist[start]+cost;
            }
        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> TC;
    while (TC--){
        cin >> N >> M >> W;
        init();
        while(M--){ // 도로 정보
            cin >> s >> e >> t;
            G.push_back({s, e, t});
            G.push_back({e, s, t}); // 도로는 방향이 없으며
        }
        while(W--){ // 웜홀 정보
            cin >> s >> e >> t;
            G.push_back({s, e, -t}); // 웜홀은 방향이 존재
        }
        bellmanFord();
    }
}