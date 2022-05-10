#include <iostream>
#define MAX 20
using namespace std;

int R, C, ans=0;
bool visit[26];
int map[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void backtracking(int r, int c, int cnt){
    ans = max(ans, cnt);
    for(int d=0; d<4; d++){
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr<0 || nr>=R || nc<0 || nc>=C) continue; // 범위를 벗어나는 경우
        if(visit[map[nr][nc]]) continue; // 이미 방문한 경우
        visit[map[nr][nc]] = true;
        backtracking(nr, nc, cnt+1);
        visit[map[nr][nc]] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        string str;
        cin >> str;
        for(int j=0; j<C; j++) map[i][j] = str[j]-'A';
    }
    visit[map[0][0]] = true;
    backtracking(0, 0, 1); // 좌측 상단에서 시작 (좌측 상단 칸도 포함)
    cout << ans;
}