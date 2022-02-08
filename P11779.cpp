#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
#define INF 1000000001
using namespace std;

struct Data {int end, weight;};

int N, M;
int cost[MAX], path[MAX];
bool visited[MAX];
vector<int> ans_path;
vector<Data> bus[MAX];

void findPath(int start, int end){ // 최소 비용 경로에 포함되는 도시들을 찾음
    ans_path.push_back(end);
    int tmp = path[end];
    while(tmp!=0){ // 역추적하여 출발지에 도착할 때 까지
        ans_path.push_back(tmp);
        tmp = path[tmp];
    }
}

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    for(int i=1; i<MAX; i++) cost[i] = INF;
    cost[start] = 0; // 출발지 cost = 0
    pq.push({0, start});
    while (!pq.empty()){
        int now_node = pq.top().second; 
        pq.pop();
        if(visited[now_node]) continue; // 방문한 경우 재방문할 필요 x
        visited[now_node] = true; // 방문하지 않은 경우 방문
        for(int i=0; i<bus[now_node].size(); i++){
            
            int next_cost = bus[now_node][i].weight;
            int next_node = bus[now_node][i].end;

            int before_cost = cost[next_node];
            int new_cost = cost[now_node] + next_cost;
            
            if(new_cost<before_cost){ // 현재 node를 거쳐가는 것이 더 최적의 경로인 경우
                cost[next_node] = new_cost;
                path[next_node] = now_node; // 다음 node로 가기 위해서는 현재 node를 지남을 의미 
                pq.push({-new_cost, next_node});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int s, e, c;
    while (M--){ // 버스 정보 저장
        cin >> s >> e >> c;
        bus[s].push_back({e, c});
    }
    int start, end; cin >> start >> end;
    dijkstra(start); // 다익스트라 (최소 비용 경로를 찾음)
    findPath(start, end); // 도착지->출발지 경로를 찾음 (---> 역출력)
    cout << cost[end] << "\n"; // 도착 도시까지 가는데 드는 최소 비용
    cout << ans_path.size() << "\n"; // 최소 비용 경로에 포함되는 도시의 개수
    for(int i=ans_path.size()-1; i>=0; i--) cout << ans_path[i] << " "; // 최소 비용 경로에 있는 도시들
}