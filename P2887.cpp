#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

typedef struct Data{int p1, p2, cost;};
bool compare(Data d1, Data d2){ return d1.cost<d2.cost; } // cost를 비교하여 오름차순 정렬

int N;
int root[MAX];
vector<pair<int, int> > X;
vector<pair<int, int> > Y;
vector<pair<int, int> > Z;
vector<Data> eg; // 행성 간 min cost 저장

int find(int x){  // root를 찾음 
    if(x==root[x]) return x;
    return root[x] = find(root[x]); // 경로 단축
}

void union_(int x, int y){ // 정점 연결
    root[find(x)] = find(y); 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y,z; cin >> N;
    for(int i=1; i<=N; i++) root[i] = i; // union-find를 위한 초기화
    for(int i=0; i<N; i++){ // 행성 위치를 입력 받음 
        cin >> x >> y >> z;
        X.push_back({x, i}); // x좌표, i번째 행성
        Y.push_back({y, i}); // y좌표, i번째 행성
        Z.push_back({z, i}); // z좌표, i번째 행성
    }
    // 메모리 초과 방지를 위해 정렬 후
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    for(int i=0; i<N-1; i++){ // 행성간 거리 계산
        eg.push_back({X[i+1].second, X[i].second, X[i+1].first-X[i].first});
        eg.push_back({Y[i+1].second, Y[i].second, Y[i+1].first-Y[i].first});
        eg.push_back({Z[i+1].second, Z[i].second, Z[i+1].first-Z[i].first});
    }
    sort(eg.begin(), eg.end(), compare);
    int ans = 0;
    for(int i=0; i<eg.size(); i++){
        if(find(eg[i].p1)!=find(eg[i].p2)){ // 연결되지 않은 경우
            union_(eg[i].p1, eg[i].p2); // 연결
            ans+=eg[i].cost; // 비용을 더해줌
        }
    }
    cout << ans;
}