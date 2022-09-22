#include<iostream>
#include<vector>
#define MAX 1001
using namespace std;

int N, M, x, y, ans=0;
int visited[MAX];
vector<int> edge[MAX];

void input(){
    cin >> N >> M;
    for(int i=0; i<M; i++){ // edge 정보 저장
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
}

void dfs(int now_node){
    visited[now_node] = true;
    for(int i=0; i<edge[now_node].size(); i++){
        int next_node = edge[now_node][i];
        if(visited[next_node]) continue;
        ans++;
        dfs(next_node);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    dfs(1);
    cout << ans;
}
