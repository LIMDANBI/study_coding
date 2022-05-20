#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

struct Data{int r, c;};
vector<Data> foodWaste;

int N, M, K, ans = 0;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(int k){
    queue<Data> q;
    int r = foodWaste[k].r;
    int c = foodWaste[k].c;
    q.push({r, c});
    visit[r][c] = true;
    int res = 0;
    while (!q.empty()){
        r = q.front().r;
        c = q.front().c;
        q.pop();
        for(int d=0; d<4; d++){
            int nr = r+dr[d];
            int nc = c+dc[d];
            if(nr<1 || nr>N || nc<1 || nc>M) continue; // 범위를 벗어나는 경우
            if(visit[nr][nc] || !map[nr][nc]) continue; // 이미 방문한 경우, 음식물 쓰레기가 아닌 경우
            visit[nr][nc] = true;
            q.push({nr,nc});
        }
        res++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<K; i++){
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
        foodWaste.push_back({r,c}); // 음식물의 위치
    }
    for(int i=0; i<K; i++) {
        if(visit[foodWaste[i].r][foodWaste[i].c]) continue; // 이미 check한 경우
        ans = max(ans, bfs(i));
    }
    cout << ans;
}