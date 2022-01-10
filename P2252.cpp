#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, indegree[32001]{};
vector<int> edge[32001];

void topologySort(){
    queue<int> q, ans;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0){
            q.push(i);
            ans.push(i);
        }
    }
    while (1){
        if(q.empty()) break;
        int x = q.front(); q.pop();
        for(int i=0; i<edge[x].size(); i++){
            indegree[edge[x][i]]--;
            if(indegree[edge[x][i]]==0){
                q.push(edge[x][i]);
                ans.push(edge[x][i]);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout << ans.front() << ' '; ans.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        edge[a].push_back(b);
        indegree[b]++;
    }
    topologySort();
}