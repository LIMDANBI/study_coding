#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 5001
#define INF 987654321
using namespace std;

struct DATA{int end, cost;};
vector<DATA> edge[MAX];

int dist[MAX];
bool visit[MAX];
int V, E, P, a, b, c;

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    for(int i=1; i<=V; i++) dist[i] = INF;
    memset(visit, false, sizeof(visit));
    dist[start] = 0;
    pq.push({0, start}); 
    while (!pq.empty()){
        int now_cost = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();
        if(visit[now_node]) continue;
        visit[now_node] = true;
        for(int i=0; i<edge[now_node].size(); i++){
            int next_node = edge[now_node][i].end;
            int next_cost = edge[now_node][i].cost;
            int before_cost = dist[next_node];
            int new_cost = dist[now_node] + next_cost;
            if(new_cost < before_cost) {
                dist[next_node] = new_cost;
                pq.push({-new_cost, next_node});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> P;
    while (E--){
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    dijkstra(1); int toP = dist[P], toV = dist[V];
    dijkstra(P); int PtoV = dist[V];
    if(toP+PtoV <= toV) cout << "SAVE HIM";
    else cout << "GOOD BYE";
}