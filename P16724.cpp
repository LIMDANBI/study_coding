#include<iostream>
#define MAX 1001
using namespace std;

int N, K, ans=0;
int map[MAX][MAX];
int visit[MAX][MAX];
int dy[] = {-1, 1, 0, 0}; // U, D, L, R
int dx[] = {0, 0, -1, 1};

void dfs(int y, int x){
    visit[y][x] = 1; // 방문
    int ny = y + dy[map[y][x]]; // 이동방향
    int nx = x + dx[map[y][x]]; // 이동방향
    if(visit[ny][nx]==0) dfs(ny, nx); // 방문하지 않은 경우 방문
    if(visit[ny][nx]==1) ans++; // 이미 방문한 경우로 cycle이 생성된 것
    visit[y][x] = -1; // 방문을 마침
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    char c; cin >> N >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++) { // 방향에 대응하는 int로 바꿔서 저장
            cin >> c; // c=='U' -> map[i][j] = 0
            if(c=='D') map[i][j] = 1;
            else if(c=='L') map[i][j] = 2;
            else if(c=='R') map[i][j] = 3;
        }
    }
    for(int i=0; i<N; i++){ // dfs 탐색을 통해 SAFE ZONE(총 cycle)의 최소 개수를 구함
        for(int j=0; j<K; j++) dfs(i, j);
    }
    cout << ans;
}