#include<iostream>
#include<vector>
#include<queue>
#define MAX_N 1001
using namespace std;

int N, M, K, s, e, c;
typedef pair<int, int> pi;
vector<pi> graph[MAX_N];
priority_queue<int> dist[MAX_N]; // 최단경로를 pq를 이용하여 저장

void dijkstra(){
    priority_queue<pi> pq;
    dist[1].push(0); // 최단경로에서 출발점 거리 = 0
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int now_cost = -pq.top().first; // 현재 node까지의 cost
        int now_node = pq.top().second; // 현재 node
        pq.pop();
        for(int i=0; i<graph[now_node].size(); i++){
            int next_node = graph[now_node][i].first; // 다음 node 
            int next_cost = now_cost + graph[now_node][i].second; // 다음 node까지 cost 
            if(dist[next_node].size() < K){ // 경로 수 k보다 작은 경우 
                dist[next_node].push(next_cost); // 경로 추가
                pq.push(make_pair(-next_cost, next_node)); // pq에 넣어서 다음 탐색 진행
            }
            else if(dist[next_node].top() > next_cost){ // 경로 수가 k 이상인 경우 -> 현재 k번째 경로보다 next_cost가 작은 경우에만 (진짜 k번쨰 경로)
                dist[next_node].pop(); // 가짜 k번째 경로 제거
                dist[next_node].push(next_cost); // 진짜 k번째 경로 추가
                pq.push(make_pair(-next_cost, next_node)); // pq에 넣어서 다음 탐색 진행
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    while (M--){
        cin >> s >> e >> c;
        graph[s].push_back(make_pair(e, c));
    }
    dijkstra();
    for(int i=1; i<=N; i++){
        if(dist[i].size() < K) cout << -1 << '\n'; // K번째 최단 경로가 존재하지 않는 경우 
        else cout << dist[i].top() << '\n'; // K번째 최단 경로가 존재하는 경우
    }
}