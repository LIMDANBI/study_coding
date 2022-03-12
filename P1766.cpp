#include<iostream>
#include<vector>
#include<queue>
#define MAX 32001
using namespace std;

int N, M, a, b;
int indegree[MAX];
vector<int> v[MAX];

void topologySort(){ // pq를 이용한 위상정렬을 통해 조건에 맞는 순서를 출력
    priority_queue<int> pq; // 가능한 쉬운 문제부터 풀기위해 priority_queue 이용
    for(int i=1; i<=N; i++){
        if(indegree[i]==0) pq.push(-i); // c++ priority_queue : max-heap => min-heap
    }
    while (!pq.empty()){
        int now = -pq.top(); pq.pop();
        cout << now << ' ';
        for(int i=0; i<v[now].size(); i++){
            int next = v[now][i]; // now 다음으로 풀 문제 
            indegree[next]--;
            if(indegree[next]==0) pq.push(-next); // 앞에 풀어야하는 문제를 다 푼 경우 priority_queue에 push
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    while (M--){
        cin >> a >> b;
        v[a].push_back(b); // A번 문제는 B번 문제보다 먼저 푸는 것이 좋음을 의미
        indegree[b]++; // 진입차수 ++
    }
    topologySort(); // pq를 이용한 위상정렬을 통해 조건에 맞는 순서를 출력
}