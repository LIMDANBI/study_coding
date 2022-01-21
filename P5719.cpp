#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX_N 501
#define INF 500001
using namespace std;

int N, M, S, D, U, V, P;
int dist[MAX_N];
bool visit[MAX_N];
vector<pair<int, int> > graph[MAX_N], inv_graph[MAX_N];

void dijkstra(){
    for(int i=0; i<N; i++) dist[i]= INF; // 최단 경로 저장 배열 초기화
    memset(visit, 0, sizeof(visit)); // 방문 여부 저장 배열 초기화
    priority_queue<pair<int, int> > pq; 
    dist[S]=0; // 시작점 거리 0
    pq.push(make_pair(0, S)); // 시작점을 priority queue(가장 가까운 경로부터 탐색)에 넣고 다익스트라 알고리즘 실행
    while(!pq.empty()){ // priority queue가 비기전까지
        int now_node = pq.top().second; // 현재 node
        pq.pop(); // pq에서 제거 
        if(visit[now_node]) continue; // 방문한 경우 다시 방문할 필요 x
        visit[now_node] = true; // 방문 여부를 true로 변환
        for(int i=0; i<graph[now_node].size(); i++){ // 연결된 다음 node들을 살펴 보면서
            int new_cost = dist[now_node]+graph[now_node][i].second; // now_node를 거쳐가는 cost
            int before_cost = dist[graph[now_node][i].first]; // 이전 cost
            if(new_cost<before_cost) { // 거쳐가는게 비용이 적을 경우
                dist[graph[now_node][i].first] = new_cost; // 경로 update
                pq.push(make_pair(-new_cost, graph[now_node][i].first)); // pq에 넣어서 다음 탐색 진행
            }
        }
    }
}

void remove_shortest(){ // 최단 경로를 제거하기 위한 bfs 탐색
    queue<int> q; 
    bool check[MAX_N] = {false, };
    q.push(D); // 도착지부터 역추척 -> 반드시 최단 경로에 포함된 간선만 지움 (역방향 그래프 사용 이유)
    while (!q.empty()){
        int now_node = q.front(); q.pop();
        if(check[now_node]) continue; // 방문한 경우 다시 방문할 필요 x 
        check[now_node] = true; // 방문 여부를 true로 변환
        for(int i=0; i<inv_graph[now_node].size(); i++){
            int next_node = inv_graph[now_node][i].first;
            if(dist[next_node]+inv_graph[now_node][i].second == dist[now_node]){  // 최단 경로에 포함되는 경우
                for(int j=0; j<graph[next_node].size(); j++){
                    if(graph[next_node][j].first == now_node)
                        graph[next_node][j].second = INF; // 경로 제거 
                }
                q.push(next_node); // 다음 node 탐색 
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (1){
        cin >> N >> M;
        if(N==0 && M==0) return 0;
        cin >> S >> D;
        for(int i=0; i<N; i++) { // graph vector 초기화
            graph[i].clear();
            inv_graph[i].clear();
        }
        for(int i=0; i<M; i++){
            cin >> U >> V >> P;
            graph[U].push_back(make_pair(V, P));
            inv_graph[V].push_back(make_pair(U, P)); // 역방향 그래프
        }
        dijkstra(); // 최단 경로 찾기
        remove_shortest(); // 최단 경로 제거 
        dijkstra(); // 거의 최단 경로 찾기
        if(dist[D]==INF) cout << -1 << '\n'; // 거의 최단 경로가 없는 경우 -1 출력
        else cout << dist[D] << '\n'; // 있으면 거의 최단 경로 길이 출력
    }
}