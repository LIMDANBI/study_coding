#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001
using namespace std;

typedef struct Data{int a, b, cost;};
bool compare(Data u, Data v) {return u.cost < v.cost;} 

int N, M, A, B, C, ans=0, maxvalue=0;
int root[MAX];
vector<Data> eg;

int find(int x){ // root를 찾음 
    if(root[x]==x) return x;
    return root[x] = find(root[x]); // 경로 단축
}

void union_(int x, int y){ // 정점 연결
    root[find(x)] = find(y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) root[i] = i; // union-find를 위한 초기화
    for(int i=0; i<M; i++){
        cin >> A >> B >> C;
        if(A!=B) eg.push_back({A, B, C});
    }
    sort(eg.begin(), eg.end(), compare); // cost를 비교하여 오름차순 정렬
    for(int i=0; i<eg.size(); i++){
        if(find(eg[i].a)!=find(eg[i].b)){ // 연결되지 않은 경우
            union_(eg[i].a, eg[i].b); // 연결
            ans+=eg[i].cost;
            if(maxvalue<eg[i].cost) maxvalue = eg[i].cost ; // 마지막에 빼 줄 경로 
        }
    }
    cout << ans-maxvalue;
}