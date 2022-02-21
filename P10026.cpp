#include<iostream>
#include<cstring>
#include<string>
#define MAX 101
using namespace std;

int N, ans=0;
char grid[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void dfs(int y, int x){
    visit[y][x] = true; // 방문 여부 update
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=N) continue; // 범위를 벗어나는 경우
        if(visit[ny][nx]) continue; // 이미 방문한 경우
        if(grid[ny][nx]!=grid[y][x]) continue; // 연결된 색상이 같은 색상이 아닌 경우
        dfs(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> N;
    for(int i=0; i<N; i++){ // 문자열 -> char
        cin >> str;
        for(int j=0; j<N; j++) grid[i][j] = str[j];
    }

    // 적록 색약이 아닌 사람
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visit[i][j]) { // 방문하지 않은 경우
                dfs(i, j); // 주변까지 탐색
                ans++;
            }
        }
    }
    cout << ans << " ";

    // 적록 색약인 사람
    // 초기화
    ans = 0;
    memset(visit, false, sizeof(visit));
    
    // red -> green
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]=='R') grid[i][j] = 'G';
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visit[i][j]) { // 방문하지 않은 경우
                dfs(i, j); // 주변까지 탐색
                ans++;
            }
        }
    }
    cout << ans;
}