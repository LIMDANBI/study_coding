#include<iostream>
#include<vector>
#include<queue>
#define MAX 50001
#define INF 987654321
using namespace std;

struct Data{int end, cost;};

int N, M;
int cost[MAX];
bool visit[MAX];
vector<Data> road[MAX];

void dijkstra(){
    priority_queue<pair<int, int> > pq;
    pq.push({0, 1}); // 시작점 : 1 
    while (!pq.empty()){
        int now_cost = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();
        if(visit[now_node]) continue; // 방문한 경우 재 방문 x 
        visit[now_node] = true;
        for(int i=0; i<road[now_node].size(); i++){
            int next_node = road[now_node][i].end;
            int next_cost = road[now_node][i].cost;
            int before_cost = cost[next_node];
            int new_cost = cost[now_node]+next_cost;
            if(new_cost < before_cost){ // 더 적은 비용이 드는 경우 Update!!
                cost[next_node] = new_cost;
                pq.push({-new_cost, next_node});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int a, b, c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        road[a].push_back({b,c});
        road[b].push_back({a,c}); // 길이 양방향
    }
    for(int i=2; i<=N; i++) cost[i] = INF; // 초기화 
    cost[1] = 0; // 시작점 : 1 
    dijkstra(); // 다익스트라 
    cout << cost[N]; // 최소값 출력
}