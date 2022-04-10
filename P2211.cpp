#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
#define INF 987654321
using namespace std;

struct Data{int computer2, cost;};

int N, M, A, B, C;

bool visit[MAX];
int dist[MAX], parent[MAX];
vector<Data> circuit[MAX];

void dijkstra(){
    for(int i=0; i<=N; i++) dist[i] = INF; // 초기화
    priority_queue<pair<int, int>> pq; // cost, nownode
    dist[1]=0; pq.push({0, 1}); // 1번 컴퓨터 = 보안 시스템을 설치할 슈퍼컴퓨터
    while (!pq.empty()){
        int nownode = pq.top().second; pq.pop();
        if(visit[nownode]) continue; // 이미 방문한 경우, pass
        visit[nownode] = true; // 방문하지 않은 경우, 방문
        for(int i=0; i<circuit[nownode].size(); i++){
            int next_node = circuit[nownode][i].computer2;
            int next_cost = circuit[nownode][i].cost;
            int before_cost = dist[next_node];
            int new_cost = dist[nownode]+next_cost;
            if(new_cost<before_cost){ // 더 적은 비용이 드는 경우 update
                dist[next_node] = new_cost;
                parent[next_node] = nownode; // 연결 정보 update
                pq.push({-new_cost, next_node});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M; // N개의 컴퓨터로 구성된 네트워크, M개의 회선 정보
    for(int i=0; i<M; i++){
        cin >> A >> B >> C;
        circuit[A].push_back({B, C});
        circuit[B].push_back({A, C}); // 모든 통신은 완전쌍방향 방식
    }
    dijkstra(); // 조건을 만족하면서 네트워크 복구
    cout << N-1 << '\n'; // 복구할 회선의 개수 
    for(int i=2; i<=N; i++) cout << parent[i] << ' ' << i << '\n'; // 복구한 회선
}