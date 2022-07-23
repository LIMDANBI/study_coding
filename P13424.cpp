#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
#define INF 987654321
using namespace std;

struct DATA{int end, cost;};

int N, M, K, a, b, c;
bool visited[MAX];
vector<DATA> v[MAX];
vector<int> friends;
int dist[MAX]; // 거리, 누적 거리

void init(){ // 초기화
    friends.clear();
    for(int i=1; i<=N; i++) v[i].clear();
}

void input(){ // 입력
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c}); // 모든 비밀통로는 양방향 통행이 가능
    }
    cin >> K; // 모임에 참여하는 친구의 수
    for(int i=0; i<K; i++){ // 모임에 참여하는 친구들
        cin >> a;
        friends.push_back(a);
    }
}

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()){
        int now_node = pq.top().second;
        pq.pop();
        if(visited[now_node]) continue; // 이미 방문한 경우 
        visited[now_node] = true; // 방문 
        for(int i=0; i<v[now_node].size(); i++){
            int next_node = v[now_node][i].end; // 다음 node
            int next_cost = v[now_node][i].cost; // now_node에서 next_node까지의 cost
            int new_cost = dist[now_node]+next_cost; // now_node를 거쳐가는 비용
            if(new_cost<dist[next_node]){
                dist[next_node] = new_cost;
                pq.push({-new_cost, next_node});
            }
        }
    }   
}

int solution(){
    int ans=0, min_dist = INF;
    for(int start=1; start<=N; start++){ // 모임에 참여하는 친구들이 현재 위치해 있는 방의 번호
        memset(visited, false, sizeof(visited)); // 방문여부 초기화
        for(int j=1; j<=N; j++) dist[j] = INF; // 거리 초기화
        dist[start] = 0; // 출발점
        dijkstra(start); // 다익스트라
        int total_dist = 0;
        for(int j=0; j<K; j++){
            int f = friends[j];
            total_dist+=dist[f];
        }
        if(total_dist<min_dist){
            min_dist = total_dist;
            ans = start;
        }
    }
    return ans; // 친구들의 이동 거리의 총합이 최소가 되도록 하는 모임 장소
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int i=0; i<T; i++){
        init();
        input();
        int ans = solution();
        cout << ans << "\n";
    }
}