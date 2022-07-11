#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

int n, m, p1, p2;
bool isfind = false;
bool visit[MAX];
vector<int> v[MAX];

void dfs(int node, int cnt){
    visit[node] = true;
    if(node == p2){
        cout << cnt;
        isfind = true;
        return;
    }
    for(int i=0; i<v[node].size(); i++){
        if(visit[v[node][i]]) continue;
        dfs(v[node][i], cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p1 >> p2 >> m;
    int x, y;
    while (m--){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0; i<v[p1].size(); i++) dfs(v[p1][i], 1);
    if(!isfind) cout << -1;
}