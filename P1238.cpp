#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX_N 1001
#define MAS_M 10001
using namespace std;

struct Data{int end, time;}; // 도착 정점, 소요 시간
int N, M, X, s, e, t, dist1[MAX_N]={}, dist2[MAX_N]={};
vector<Data> graph[MAX_N], iv_graph[MAX_N];
bool visit[MAX_N];
void dijkstra(vector<Data> G[MAX_N]);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M>>X;
    for(int i=0; i<M; i++){
        cin>>s>>e>>t;
        graph[s].push_back({e, t}); // 정방향 그래프
        iv_graph[e].push_back({s, t}); // 역방향 그래프
    }
    dijkstra(graph); // 정방향 그래프 다익스트라 알고리즘 수행
    dijkstra(iv_graph); // 역방향 그래프 다익스트라 알고리즘 수행
    int ans = 0; 
    for(int i=1; i<=N; i++) ans=max(ans, dist2[i]); // 최대 시간 찾기
    cout << ans;
}

void dijkstra(vector<Data> G[MAX_N]){
    for(int i=1; i<=N; i++) {
        dist1[i] = INF;
        visit[i] = false;
    }
    dist1[X]=0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, X));
    while (!pq.empty()){
        int curNode = pq.top().second; pq.pop();
        if(visit[curNode]) continue; // 이미 방문한 경우
        visit[curNode] = true;
        for(int i=0; i<G[curNode].size(); i++){
            int newTime = dist1[curNode]+G[curNode][i].time; // curNode를 거치는 경우
            int beforeTime = dist1[G[curNode][i].end]; // curNode를 거치지 않는 경우 
            if(newTime<beforeTime){ // 더 짧은 시간이 걸리는 경우 update 
                dist1[G[curNode][i].end] = newTime;
                pq.push(make_pair(-newTime, G[curNode][i].end));
            }
        }
    }
    for(int i=1; i<=N; i++) dist2[i]+=dist1[i];
}