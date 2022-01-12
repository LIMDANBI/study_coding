#include<iostream>
#include<vector>
#define MAX_N 50001
using namespace std;

int N, M, a, b;
int parent[MAX_N]{}, depth[MAX_N]{}; //각 node의 parent, depth 저장
bool visit[MAX_N]={false}; // 방문 여부 (dfs에서 이용)
vector<int> v[MAX_N]; // edge

void dfs(int n, int d){ // dfs 탐색을 통해 각 node의 depth와 부모 정보 저장
    visit[n]=true;
    depth[n]=d; // depth 저장
    for(int i=0; i<v[n].size(); i++){
        int nextnode = v[n][i];
        if(!visit[nextnode]) {
            parent[nextnode] = n; // 부모 정보 저장
            dfs(nextnode, d+1);  // 다음 노드 방문
        }
    }
}

int lca(int x, int y){
    while (depth[x]!=depth[y]){ // depht가 다를 경우, depth를 맞춤
        if(depth[x]<depth[y]) y = parent[y];
        else x = parent[x];
    }
    while (x!=y){ // 공통 조상을 가질 때 까지 반복
        x = parent[x];
        y = parent[y];
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0; i<N-1; i++){
        cin>>a>>b;
        v[a].push_back(b); 
        v[b].push_back(a); // 트리는 무방향 
    }
    dfs(1, 0); // tree의 root는 1번
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        cout << lca(a, b) << '\n';
    }
}