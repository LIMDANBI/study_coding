#include<iostream>
#include<cstring>
#define MAX 51
using namespace std;

int N, M, K=1, safe_zone, max_safe_zone=0;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> map[i][j];
    }
}

void dfs(int y, int x, int k){
    if(y<0 || y>=N || x<0 || x>=M) return; // 범위를 벗어나는 경우 
    if(visited[y][x] || map[y][x]<=k) return; // 이미 방문한 경우, 물에 잠기는 경우
    visited[y][x] = true;
    for(int d=0; d<4; d++) dfs(y+dy[d], x+dx[d], k);
}

void solution(){
    for(int k=1; k<=100; k++){
        memset(visited, false, sizeof(visited));
        safe_zone = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(visited[i][j] || map[i][j]<=k) continue;
                safe_zone++;
                dfs(i, j, k);
            }
        }
        if(max_safe_zone<safe_zone){
            K = k;
            max_safe_zone = safe_zone;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << K << " " << max_safe_zone;
}
