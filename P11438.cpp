#include<iostream>
#include <cstring> // memset
#include<algorithm> // swap
#include<vector>
#define MAX_N 100001
#define MAX_K 17 // log2(MAX_N)
using namespace std;

int N, M, a, b;
int depth[MAX_N], dp[MAX_K+1][MAX_N];
bool visit[MAX_N];
vector<int> v[MAX_N];

void dfs(int n, int d){ // dfs 탐색을 통해 각 node의 depth와 부모 정보 저장
    visit[n] = true; // visit 여부 update
    depth[n] = d; // depth 저장
    for(int i=0; i<v[n].size(); i++){
        int nextnode = v[n][i];
        if(!visit[nextnode]){ // 방문하지 않은 경우
            dp[0][nextnode] = n; // 부모(2^0 번째 조상) 정보 저장 
            dfs(nextnode, d+1); // 다음 노드 방문
        }
    }
}

void setDP(){
    for(int i=1; i<MAX_K; i++){ // 2^k번째 조상 노드까지 저장
        for(int j=1; j<=N; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

int lca(int x, int y){
    if(depth[y]<depth[x]) swap(x, y);
    for(int i=MAX_K; i>=0; i--){
        if(depth[y]-depth[x] >= 1<<i) 
            y = dp[i][y]; // depth를 맞춰줌
    }
    if(x==y) return x;
    for(int i=MAX_K; i>=0; i--){ // 공통 조상을 가질 때 까지 반복
        if(dp[i][x]!=dp[i][y]){ 
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0; i<N-1; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a); // 트리는 무방향
    }
    memset(visit, false, sizeof(visit)); // false로 초기화
    dfs(1, 0); // tree의 root는 1번
    setDP(); // dp를 통해 2^k번째 조상 노드까지 저장
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        cout << lca(a,b) << '\n';
    }
}