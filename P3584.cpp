#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define MAX_N 10001
#define MAX_K 13
using namespace std;

int T, N, A, B;
int depth[MAX_N];
bool visit[MAX_N];
int dp[MAX_N][MAX_K+1];
vector<int> tree[MAX_N];

void dfs(int n, int d){ // dfs 탐색을 통해 각 node의 depth 정보 저장
    visit[n] = true; // visit 여부 update
    depth[n] = d; // depth 저장
    for(int i=0; i<tree[n].size(); i++){
        int nextnode = tree[n][i];
        if(visit[nextnode]) continue; // 아마 방문한 경우 pass
        dfs(nextnode, d+1); // 다음 노드 방문
    }
}

void init(){ // 2^k번째 조상까지의 정보 저장
    for(int i=1; i<=MAX_K; i++){
        for(int j=1; j<=N; j++) dp[j][i] = dp[dp[j][i-1]][i-1];
    }
}

int lca(int x, int y){ // LCA(최소공통조상) 반환
    if(depth[y]<depth[x]) swap(x, y); // y가 더 깊음을 보장
    for(int i=MAX_K; i>=0; i--){
        if(depth[y]-depth[x] >= 1<<i) y = dp[y][i]; // depth를 맞춰줌
    }
    if(x==y) return x; // x 가 LCA인 경우
    for(int i=MAX_K; i>=0; i--){ // LCA를 가질 때 까지 반복
        if(dp[x][i]!=dp[y][i]){
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--){
        cin >> N;

        // 초기화
        memset(visit, 0, sizeof(visit));
        memset(depth, 0, sizeof(depth));
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=N; i++) tree[i].clear();

        for(int i=0; i<N-1; i++){
            cin >> A >> B;
            tree[A].push_back(B);
            tree[B].push_back(A); // tree는 양방향
            dp[B][0] = A; // A가 B의 부모
        }
        int root;
        for(int i=1; i<=N; i++){ // root를 찾음
            if(dp[i][0]==0) {
                root = i;
                break;
            }
        }
        int a, b; 
        cin >> a >> b;
        dfs(root, 0); // depth 저장 
        init(); // 2^k번째 조상까지의 정보 저장
        cout << lca(a, b) << "\n";
    }
}