#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define MAX_N 100001
#define MAX_K 17

using namespace std;

int N, K, A, B, C, D, E, minroad, maxroad;
struct Data{int end, cost;};
vector<Data> tree[MAX_N];
int depth[MAX_N];
bool visit[MAX_N];
int dpTree[MAX_N][MAX_K+1], dpMax[MAX_N][MAX_K+1], dpMin[MAX_N][MAX_K+1];

void dfs(int n, int d){ // dfs 탐색을 통해 각 node의 depth와 부모 정보 저장
    visit[n] = true; // visit 여부 update
    depth[n] = d; // depth 저장
    for(int i=0; i<tree[n].size(); i++){
        int nextnode = tree[n][i].end;
        int dist = tree[n][i].cost;
        if(!visit[nextnode]){
            dpTree[nextnode][0] = n; // 부모(2^0 번째 조상) 정보 저장 
            dpMin[nextnode][0] = dpMax[nextnode][0] = dist; // 노드간 거리(가중치) 저장
            dfs(nextnode, d+1); // 다음 노드 방문
        }
    }
}

void init(){
    for(int i=1; i<=MAX_K; i++){
        for(int j=1; j<=N; j++){
            dpTree[j][i] = dpTree[dpTree[j][i-1]][i-1];
            dpMin[j][i] = min(dpMin[j][i-1], dpMin[dpTree[j][i-1]][i-1]);
            dpMax[j][i] = max(dpMax[j][i-1], dpMax[dpTree[j][i-1]][i-1]);
        }
    }
}

void lca(int x, int y){
    minroad=1e9; maxroad=0; // 초기화
    if(depth[y]<depth[x]) swap(x, y); // depth[y]가 더 깊음을 보장
    for(int i=MAX_K; i>=0; i--){ // depth를 맞춰줌
        if(depth[y]-depth[x] >= 1<<i) {
            minroad = min(minroad, dpMin[y][i]);
            maxroad = max(maxroad, dpMax[y][i]);
            y=dpTree[y][i];
        }
    }
    if(x!=y){ // x==y : x가 lca인 경우
        for(int i=MAX_K; i>=0; i--){ // lca를 가질 때 까지 반복
            if(dpTree[x][i]!=dpTree[y][i]){
                minroad = min({minroad, dpMin[x][i], dpMin[y][i]});
                maxroad = max({maxroad, dpMax[x][i], dpMax[y][i]});
                x = dpTree[x][i];
                y = dpTree[y][i];
            }
        }
        minroad = min({minroad, dpMin[x][0], dpMin[y][0]});
        maxroad = max({maxroad, dpMax[x][0], dpMax[y][0]});
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    // tree를 만듦
    for(int i=0; i<N-1; i++){
        cin >> A >> B >> C;
        tree[A].push_back({B, C});
        tree[B].push_back({A, C});
    }
    // 초기화
    memset(visit, 0, sizeof(visit));
    for(int i=1; i<=MAX_K; i++){
        for(int j=1; j<=N; j++){
            dpMin[i][j] = 1e9;
        }
    }
    dfs(1, 0); // dfs 탐색을 통해 깊이, 거리 저장
    init(); // dp 배열들 구축 (2^K번째 조상 까지의 정보 저장)
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> D >> E;
        lca(D, E); // D와 E 사이 최단, 최장 도로의 거리를 구함
        cout << minroad << " " << maxroad << '\n';
    }
}