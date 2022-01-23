#include<iostream>
#include<cstring>
#define MAX_N 100001
using namespace std;

int N, M, a, b, w;
char op;
int parent[MAX_N];
long long dist[MAX_N]; // dist[x]=y : node x 는 root node 보다 y만큼 무겁다! 

int find(int node){
    if(parent[node] == node) return node; // root node의 번호는 자기 자신
    int p = find(parent[node]); // 상위 node dist 먼저 update
    dist[node]+=dist[parent[node]]; // dist update
    return parent[node] = p;
}

void uni(int a, int b, int w){
    int roota = find(a), rootb = find(b);  // a, b의 루트 노드를 찾음
    if(roota == rootb) return;
    dist[rootb] = dist[a]-dist[b]+w; // dist 저장
    parent[rootb] = roota; // b를 a의 자손으로 넣어 두 트리를 합침
}

int main(){
    while (1){
        ios_base::sync_with_stdio(0); cin.tie(0);
        cin >> N >> M;
        if(N==0 && M==0) return 0;
        for(int i=0; i<=N; i++) parent[i] = i; // 처음에 root node는 자신
        memset(dist, 0, sizeof(dist)); // dist 배열 초기화 
        while (M--){
            cin>> op;
            if(op=='!'){ // 무게를 재는 경우
                cin >> a >> b >> w;
                uni(a, b, w);
            }
            else if(op=='?'){ // 교수님의 질문인 경우
                cin >> a >> b;
                if(find(a)!=find(b)) cout << "UNKNOWN\n"; // 비교가 불가능한 경우
                else cout << dist[b]-dist[a] << '\n'; // 비교가 가능한 경우
            }
        }   
    }
}