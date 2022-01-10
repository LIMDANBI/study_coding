#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, a, b, c;
struct edge { int node1, node2, weight; }; // 정점 1, 정점 2, 두 정점 간 비용
bool compare(edge u, edge v) { return u.weight < v.weight; } // 비용이 작은 순으로 정렬
int root[1001];
vector<edge> eg;

int find(int x){
    if(root[x]==x) return x;
    return root[x] = find(root[x]); // 경로 압축
}

void uni(int x, int y){
    root[find(x)] = find(y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) root[i] = i;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        if(a!=b) eg.push_back({a,b,c});
    }
    sort(eg.begin(), eg.end(), compare);
    int ans = 0;
    for(int i=0; i<eg.size(); i++){
        if(find(eg[i].node1)!=find(eg[i].node2)){
            uni(eg[i].node1, eg[i].node2);
            ans+=eg[i].weight;
        }
    }
    cout << ans;
}