#include<iostream>
#include<vector>
#define INF 2100000000
#define MAX_N 501
using namespace std;

int N, M;
bool cycle = false;
long long dist[MAX_N];
vector<pair<int, int> > graph[MAX_N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int a, b, c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }

    for(int i=2; i<=N; i++) dist[i] = INF; // 초기화
    dist[1] = 0; // 1번 정점에서 출발

    // 벨만-포드 알고리즘
    for(int i=1; i<=N; i++){ // 반복문을 N-1번 돌면 최단 거리 완성
        for(int j=1; j<=N; j++){
            for(int k=0; k<graph[j].size(); k++){
                int next_node = graph[j][k].first;
                int next_cost = graph[j][k].second;
                if(dist[j]!=INF && dist[j]+next_cost<dist[next_node]){
                    dist[next_node] = dist[j]+next_cost;
                    if(i==N) cycle = true; // 반복문을 한번 더 돌렸을 때 최단 거리 update = 음의 싸이클 존재
                }
            }
        }
    }
    if(cycle) cout << -1 << '\n'; // cycle이 있는 경우 (시간을 무한히 오래 전으로 되돌릴 수 있는 경우)
    else{
        for(int i=2; i<=N; i++){
            if(dist[i]==INF) cout << -1 << '\n'; // 해당 도시로 가는 경로가 없는 경우
            else cout << dist[i] << '\n'; // 해당 도시로 가는 최단 경로
        }
    }
}