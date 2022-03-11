#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
using namespace std;

int N, M;
int indegree[MAX];
vector<int> edge[MAX], ans;

void topologySort(){ // 위상정렬을 통해 가수들의 출연 순서를 정함
    queue<int> q;
    for(int i=1; i<=N; i++){ // 진입 차수가 0인 node(제일 앞서는 node)를 queue에 넣고 시작
        if(indegree[i]==0) q.push(i);
    }
    while (!q.empty()){
        int s = q.front(); q.pop();
        ans.push_back(s);

        for(int i=0; i<edge[s].size(); i++){
            int next = edge[s][i]; // 다음 이어지는 node
            indegree[next]--; // 진입 차수 --
            if(indegree[next]==0) q.push(next); // 진입 차수가 0이 된 node를 queue에 집어 넣음
        }
    }
    if(ans.size()!=N) cout << 0; // 순서를 정하는 것이 불가능한 경우, 0 출력
    else { // 가능한 경우, 순서 출력
        for(int i=0; i<N; i++) cout << ans[i] << '\n';
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    while(M--){
        int sNum, s1, s2; cin >> sNum;
        if(sNum==0) continue; cin >> s1;
        if(sNum==1) continue;
        for(int s=0; s<sNum-1; s++){
            cin >> s2;
            edge[s1].push_back(s2); // s1 > s2 (s1이 s2보다 먼저) 의미
            indegree[s2]++; // 진입 차수 ++
            s1 = s2; // 다음 순서 비교를 위한 이전 순서 저장
        }
    }
    topologySort(); // 위상정렬 후 정답 출력
}