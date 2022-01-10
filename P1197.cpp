#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V, E, a, b, c, root[10001]{};
struct edge {int node1, node2, weight;}; // edge 구조체
bool compare(edge u, edge v) {return u.weight < v.weight;} // weight로 비교하여 정렬
vector<edge> eg; //edge type 벡터

int find(int x){ // root를 찾음 
    if(root[x]==x) return x;
    return root[x] = find(root[x]); // 경로 단축
}

void union_(int x, int y){ // 정점 연결
    root[find(x)] = find(y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>V>>E;
    for(int i=1; i<=V; i++) root[i] = i; // union-find를 위한 초기화
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        if(a!=b) eg.push_back({a,b,c});
    }
    sort(eg.begin(), eg.end(), compare); // 오름차순 정렬
    
    int ans = 0;
    for(int i=0; i<eg.size(); i++){
        if(find(eg[i].node1)!=find(eg[i].node2)) { // 연결되지 않은 경우
            union_(eg[i].node1, eg[i].node2); // 연결
            ans+=eg[i].weight; // 연결된 weight를 답에 더해줌
        }
    }
    cout << ans;
}