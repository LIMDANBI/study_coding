#include<iostream>
#define MAX 50
using namespace std;

int N, M, R, C, D, ans=0;
int space[MAX][MAX];
int dr[] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dc[] = {0, 1, 0, -1};

int direction(int d){ // 현재 방향에서 왼쪽 방향을 반환
    if(d==0) return 3;
    if(d==1) return 0;
    if(d==2) return 1;
    if(d==3) return 2;
}

void clean(int r, int c, int d){
    if(space[r][c]==0){
        space[r][c] = -1; // 현재 위치를 청소
        ans++;
    }
    for(int i=0; i<4; i++){ // 조건에 따라 탐색 진행
        int nd = direction(d);
        int nr = r + dr[nd];
        int nc = c + dc[nd];

        if(nr<0 || nr>=N || nc<0 || nc>=M) continue; // 범위를 벗어나는 경우
        if(space[nr][nc]==0) clean(nr, nc, nd); // 청소가 가능한 경우
    }

    // 뒤로 한칸 후진
    int nd = (d+2)%4;
    int nr = r + dr[nd];
    int nc = c + dc[nd];

    if(nr<0 || nr>=N || nc<0 || nc>=M || space[nr][nc]==1) return; // 범위를 벗어나거나, 뒤에 벽이 있어 후진하지 못하는 경우
    clean(nr, nc, d); // 후진할 수 있는 경우, 방향을 유지하며 후진
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M; // 로봇 청소기가 있는 장소는 N × M
    cin >> R >> C >> D; // (r, c) : 로봇 청소기가 있는 칸의 좌표 , d : 바라보는 방향 (0:북 / 1:동 / 2:남 / 3:서)
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> space[i][j];
    }
    clean(R, C, D); // 로봇 청소기가 있는 칸 부터 청소를 시작
    cout << ans;
}