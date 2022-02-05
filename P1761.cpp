#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_N 40001
#define MAX_K 16
using namespace std;

struct Data{int end, dist;};

int N, M;
int depth[MAX_N]; // 노드의 depth 저장
bool visit[MAX_N]; // dfs 탐색 시 방문 여부 체크
int dp[MAX_N][MAX_K]; // 2^k번째 조상까지 저장
int dpDist[MAX_N][MAX_K]; // 거리의 합 정보 저장 
vector<Data> tree[MAX_N]; // tree의 정보 저장

void dfs(int n, int d){
    depth[n] = d; // depth 저장
    visit[n] = true; // 방문
    for(int i=0; i<tree[n].size(); i++){
        int next = tree[n][i].end; // 다음 방문할 node
        int dist = tree[n][i].dist; // 다음 node 까지의 거리
        if(visit[next]) continue; // 이미 방문한 경우
        dp[next][0] = n; // 부모 정보 저장
        dpDist[next][0] = dist; // 거리 정보 저장
        dfs(next, d+1); // dfs 탐색
    }
}

void init(){ // 2^k번째 조상까지의 정보 저장
    for(int i=1; i<MAX_K; i++){
        for(int j=1; j<=N; j++){
            dp[j][i] = dp[dp[j][i-1]][i-1]; // node
            dpDist[j][i] = dpDist[j][i-1] + dpDist[dp[j][i-1]][i-1]; // dist
        }
    }
}

int lca(int x, int y){
    int ans = 0;
    if(depth[y]<depth[x]) swap(x, y); // y가 더 깊음을 보장
    for(int i=MAX_K-1; i>=0; i--){ // x, y의 depth를 맞춤
        if(depth[y]-depth[x] >= 1<<i){
            ans+=dpDist[y][i];
            y = dp[y][i];
        }
    }
    if(x==y) return ans; // x가 LCA(최소 공통 조상)인 경우
    for(int i=MAX_K-1; i>=0; i--){ // lca를 가지기 위해 
        if(dp[x][i]!=dp[y][i]){
            ans+=dpDist[x][i];
            ans+=dpDist[y][i];
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    ans+=(dpDist[x][0]+dpDist[y][0]);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int s, e, d;
    for(int i=0; i<N-1; i++){ // tree를 만듦
        cin >> s >> e >> d;
        tree[s].push_back({e, d});
        tree[e].push_back({s, d}); // tree는 양방향
    }
    dfs(1, 0); // 거리, 부모노드 정보 저장
    init(); // 2^k번째 조상까지의 정보 저장
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> s >> e;
        cout << lca(s, e) << '\n';
    }
}