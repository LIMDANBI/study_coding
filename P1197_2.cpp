// MST 프림 알고리즘
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, a, b, c;
bool visit[10001];
vector<pair<int, int>> edge[10001];

int prim(){
    int ans = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1}); // 1번 정점부터 시작
    while (!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visit[node]) continue;
        visit[node] = true;
        ans+=cost;
        for(int i=0; i<edge[node].size(); i++){
            cost = edge[node][i].first;
            if(visit[edge[node][i].second]) continue;
            pq.push({edge[node][i]}); // 현재 정점에서 이동 가능한 방문하지 않은 정점
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        edge[a].push_back({-c, b}); // max heap to min heap 
        edge[b].push_back({-c, a});
    }
    cout << prim();
}