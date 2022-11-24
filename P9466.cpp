#include<iostream>
#include<cstring>
#include<vector>
#define MAX 100001
using namespace std;

int N;
int arr[MAX];
bool isteam[MAX], visited[MAX];

vector<int> v;

void init(){
    memset(isteam, false, sizeof(isteam));
    memset(visited, false, sizeof(visited));
}

void input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
}

void dfs(int start, int next){
    if(visited[next]){ // 이미 방문한 경우
        if(start == next){
            for(int i=0; i<v.size(); i++) isteam[v[i]] = true;
        }
        else{
            for(int i=0; i<v.size(); i++) visited[v[i]] = false;
        }
        return;
    }
    visited[next] = true;
    v.push_back(next);
    dfs(start, arr[next]);
}

void solution(){
    for(int start=1; start<=N; start++){
        int next = arr[start];
        if(visited[next]) continue;
        visited[start] = true;
        v.push_back(start);
        dfs(start, next);
        v.clear();
    }
}

void output(){
    int ans = 0; // 프로젝트 팀에 속하지 못한 학생들의 수
    for(int i=1; i<=N; i++){
        if(!isteam[i]) ans++;
    } cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        init();
        input();
        solution();
        output();
    }
}