#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M, V;
bool visit[MAX];
vector<int> v[MAX];

void dfs(int n){
    visit[n] = true;
    cout << n << " ";
    for(int i=0; i<v[n].size(); i++){
        int next = v[n][i];
        if(!visit[next]) dfs(next); // 재귀적으로 구현
    }
}

void bfs(int n){
    queue<int> q;
    q.push(n);
    visit[n] = true;
    while (!q.empty()){ // queue를 이용하연 구현
        int now = q.front();
        q.pop();
        cout << now << " ";
        for(int i=0; i<v[now].size(); i++){
            int next = v[now][i];
            if(visit[next]) continue;
            visit[next] = true;
            q.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> V;
    for(int i=0; i<M; i++){
        int a, b; 
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); // 입력으로 주어지는 간선은 양방향
    }
    for(int i=1; i<=N; i++) sort(v[i].begin(), v[i].end()); // 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
    dfs(V); cout << "\n";
    memset(visit, false, sizeof(visit)); // visit 배열 초기화
    bfs(V);
}