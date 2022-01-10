#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, indegree[501]{}, dp[501]{}, times[501]{};
vector<int> edge[501];

void topologySort(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) {
            q.push(i);
            dp[i] = times[i];
        }
    }
    while(1){
        if(q.empty()) break;
        int x = q.front(); q.pop();
        for(int i=0; i<edge[x].size(); i++){
            dp[edge[x][i]] = max(dp[edge[x][i]], dp[x]+times[edge[x][i]]);
            indegree[edge[x][i]]--;
            if(indegree[edge[x][i]]==0) q.push(edge[x][i]);
        }
    }
    for(int i=1; i<=n; i++) cout << dp[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        int t; cin>>t; times[i] = t;
        while (1){
            int before; cin>>before;
            if(before==-1) break; 
            indegree[i]++;
            edge[before].push_back(i);
        }
    }
    topologySort();
}