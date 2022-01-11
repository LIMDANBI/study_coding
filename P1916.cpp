#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 987654321
#define MAX_N 1001
#define MAX_M 100001

int N, M, S, E, dist[MAX_N]{};
struct Data{int end, weight;};
vector<Data> eg[MAX_M];

void dijkstra(){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, S));
    while (!pq.empty()){
        int nownode = pq.top().second; 
        int distance = pq.top().first*(-1);
        pq.pop();
        if(dist[nownode]<distance) continue; //이미 담긴 것보다 distance가 크면 pass
        for(int i=0; i<eg[nownode].size(); i++){
            int new_cost = dist[nownode] + eg[nownode][i].weight;
            int before_cost = dist[eg[nownode][i].end];
            if(new_cost<before_cost){
                dist[eg[nownode][i].end] = new_cost;
                pq.push(make_pair(-1*new_cost, eg[nownode][i].end));
            }
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int s, e, w; cin>>s>>e>>w;
        eg[s].push_back({e, w});
    }
    cin>>S>>E;
    for(int i=0; i<MAX_N; i++) dist[i] = INF;
    dist[S] = 0;
    dijkstra();
    cout << dist[E];
}