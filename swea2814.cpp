#include<iostream>
#include<vector>
#define MAX 11
using namespace std;

int N, M, ans;
bool visited[MAX];
vector<int> edge[MAX];

void init(){
    ans = 1;
    for(int i=0; i<MAX; i++) {
        edge[i].clear();
        visited[i] = false;
    }
}

void input(){
    int x, y;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
}

int dfs(int node, int len){
    ans = max(ans, len);
    for(int i=0; i<edge[node].size(); i++){
        int next_node = edge[node][i];
        if(visited[next_node]) continue;
        visited[next_node] = true;
        dfs(next_node, len+1);
        visited[next_node] = false;
    }
}

void solution(){
    for(int i=1; i<=N; i++){
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        init();
        input();
        solution();
        cout << "#" << t << " " << ans << "\n";
    }
}