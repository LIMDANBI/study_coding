#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 8
using namespace std;

typedef pair<int, int> pi;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int tmp_lab[MAX][MAX];
vector<pi> virus;
int N, M, ans=0;

void bfs(int y, int x){ // 바이러스 확산
    queue<pi> q; q.push({y, x});

    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nr = r+dy[i];
            int nc = c+dx[i];
            if(0<=nr && nr<N && 0<=nc && nc<M && tmp_lab[nr][nc]==0){ // 범위 내에 있고 바이러스가 확산될 수 있는 경우
                tmp_lab[nr][nc]=2; // 바이러스 확산
                q.push({nr, nc});  // 다음 확산 여부 탐색
            }
        }
    }
}

void wall(int idx, int w, int lab[MAX][MAX]){ // 벽을 세움
    if(w==0){ // 벽 3개를 전부 세운 경우
        int cnt=0;
        copy(&lab[0][0], &lab[0][0]+64, &tmp_lab[0][0]); // copy 후 bfs(바이러스 확산) 진행
        for(int i=0; i<virus.size(); i++) // 저장해 둔 바이러스 위치에서
            bfs(virus[i].first, virus[i].second); // 바이러스를 확산시킴
        for(int i=0; i<N; i++){ // bfs(바이러스 확산) 진행 후 안전 영역 count
            for(int j=0; j<M; j++){
                if(tmp_lab[i][j]==0) cnt++; // 안전 영역인 경우, ++
            }
        }
        ans = max(ans, cnt); // 더 큰 안전 영역을 가지는 경우 정답 Update
        return ;
    }
    for(int i=idx; i<N*M; i++){
        if(lab[i/M][i%M]==0){ // 벽을 세울 수 있는 경우
            lab[i/M][i%M] = 1; // 벽을 세음
            wall(i, w-1, lab); // 추가로 더 벽을 세워야하는지
            lab[i/M][i%M] = 0; // 벽 해제
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int lab[MAX][MAX];
    cin >> N >> M; // 연구소 크기 : N x M
    for(int i=0; i<N; i++){ // 연구소 상태 입력
        for(int j=0; j<M; j++) {
            cin >> lab[i][j];
            if(lab[i][j]==2) virus.push_back({i, j}); // 바이러스 위치 저장 
        }
    }
    wall(0, 3, lab); // 벽을 세울 수 있는 모든 경우의 수에서 안전영역의 최대 크기를 구함 (brute force)
    cout << ans;
}