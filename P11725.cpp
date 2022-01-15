#include<iostream>
#include<vector>
using namespace std;

int N;
int parent[100001]; // 해당 번호의 node의 부모 저장
bool visit[100001]={0, }; // 방문 여부 저장
vector<int> tree[100001]; // tree 저장

void dfs(int n){
    visit[n]=true; // 방문
    for(int i=0; i<tree[n].size(); i++){
        int child = tree[n][i];
        if(!visit[child]){ // child를 방문하지 않은 경우
            parent[child] = n; // 부모 정보 update
            dfs(child); // child 방문
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b; cin>>N;
    for(int i=1; i<N; i++){ // tree를 만듦
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1); // dfs를 진행하면서 부모 노드 정보 저장
    for(int i=2; i<=N; i++) cout << parent[i] << '\n'; // 저장해둔 부모 정보 출력
}