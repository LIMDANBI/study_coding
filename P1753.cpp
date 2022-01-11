#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

int V, E, K, dist[MAX_V]{};
struct node{int end, weight;};
vector<node> eg[MAX_E];

void dijkstra(){
    priority_queue<pair<int, int>> pq; // <cost, nownode>
    pq.push(make_pair(0, K));
    
    while (!pq.empty()){
        int nownode = pq.top().second;
        pq.pop();
        for(int i=0; i<eg[nownode].size(); i++){ // 주변 값 update
            int new_cost = dist[nownode] + eg[nownode][i].weight;
            int before_cost = dist[eg[nownode][i].end];
            if(new_cost<before_cost){ // update
                dist[eg[nownode][i].end]= new_cost;
                pq.push(make_pair(-1*new_cost, eg[nownode][i].end));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>V>>E>>K;
    for(int i=0; i<E; i++){
        int u, v, w; cin>>u>>v>>w;
        eg[u].push_back({v, w});
    }
    for(int i=1; i<=V; i++) dist[i] = INF;
    dist[K] = 0; // 시작점
    dijkstra();
    for(int i=1; i<=V; i++){
        if(dist[i] == INF) cout << "INF\n"; // 경로가 존재하지 않는 경우
        else cout << dist[i] << '\n'; // 최단 경로
    }
}