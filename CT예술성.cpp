#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX 101
using namespace std;

struct edge{int end, cost;};

int n, m;
int dist[MAX];
vector<edge> v[MAX];

void input(){
    int start, end, cost;
    cin >> n >> m;
    while(m--){
        cin >> start >> end >> cost;
        v[start].push_back({end, cost}); // 단방향 그래프
    }
}

void init(){
    dist[1] = 0; // 1번 정점에서 출발
    for(int i=2; i<=n; i++) dist[i] = INF;
}

void solution(){
    priority_queue<pair<int, int>> pq; // 가중치, 다음 노드
    pq.push({0, 1});
    init();
    while(!pq.empty()){
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;
        pq.pop();
        if(dist[now_node] < now_cost) continue; // 시간 초과 방지
        for(int i=0; i<v[now_node].size(); i++){
            int next_cost = v[now_node][i].cost;
            int next_node = v[now_node][i].end;
            if(dist[now_node]+next_cost < dist[next_node]){
                dist[next_node] = dist[now_node]+next_cost;
                pq.push({-next_cost, next_node}); // max heap to min heap
            }
        }
    }
}

void output(){
    for(int i=2; i<=n; i++) {
        if(dist[i]==INF) cout << "-1\n";
        else cout << dist[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie();
    input();
    solution();
    output();
}