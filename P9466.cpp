#include<iostream>
#include<cstring>
#define MAX 100001
using namespace std;

int N, cnt;
int arr[MAX];
bool isteam[MAX], visited[MAX];

void init(){
    cnt = 0;
    memset(isteam, false, sizeof(isteam));
    memset(visited, false, sizeof(visited));
}

void input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
}

void dfs(int node){
    visited[node] = true;
    int next = arr[node];

    if(!visited[next]) dfs(next);
    else if(!isteam[next]){
        for(int i=next; i!=node; i = arr[i]) cnt++;
        cnt++;
    }
    isteam[node] = true;
}

void solution(){
    for(int start=1; start<=N; start++){
        if(visited[start]) continue;
        dfs(start);
    }
    cout << N-cnt << "\n"; // 프로젝트 팀에 속하지 못한 학생들의 수
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        init();
        input();
        solution();
    }
}