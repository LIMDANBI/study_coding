#include<iostream>
#include<cstring>
#include<vector>
#define MAX 8
using namespace std;

struct Data {int type, row, col;};
int dr[] = {0, 1, 0, -1}; // 시계방향 순서로 초기화
int dc[] = {1, 0, -1, 0};

int N, M, ans;
vector<int> dir; // cctv 방향
vector<Data> cctv; // cctv 종류, 위치(r), 위치(c)
int office[MAX][MAX], copy_office[MAX][MAX];

void check(int r, int c, int d){ // cctv로 감시 가능한 영역 check
    int nr = r, nc = c;
    while (0<=nr && nr<N && 0<=nc && nc<M){ // 범위를 벗어나지 않는 경우
        if(office[nr][nc]==6) break; // 벽인 경우
        copy_office[nr][nc] = office[r][c]; // cctv로 감시 가능한 영역 check
        nr+=dr[d]; nc+=dc[d]; // 감시 영역 계속해서 탐색
    }
}

void solve(int now){
    if(now == cctv.size()){ // cctv 방향 설정이 끝난 경우 
        memcpy(copy_office, office, sizeof(office)); // 배열 복사 
        for(int i=0; i<cctv.size(); i++){ // cctv로 감시 가능한 영역 check
            int r = cctv[i].row;
            int c = cctv[i].col;

            if(cctv[i].type == 1) check(r, c, dir[i]);
            else if(cctv[i].type == 2){
                check(r, c, dir[i]);
                check(r, c, (dir[i]+2)%4);
            }
            else if(cctv[i].type == 3){
                check(r, c, dir[i]);
                check(r, c, (dir[i]+1)%4);
            }
            else if(cctv[i].type == 4){
                check(r, c, dir[i]);
                check(r, c, (dir[i]+1)%4);
                check(r, c, (dir[i]+2)%4);
            }
            else if(cctv[i].type == 5){
                check(r, c, dir[i]);
                check(r, c, (dir[i]+1)%4);
                check(r, c, (dir[i]+2)%4);
                check(r, c, (dir[i]+3)%4);
            }
        }
        int cnt = 0;
        for(int i=0; i<N; i++){ // 감시할 수 없는 영역 check
            for(int j=0; j<M; j++){
                if(copy_office[i][j]==0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    for(int i=0; i<4; i++){
        dir[now]=i; // 방향 설정
        solve(now+1); // 다음 cctv 방향 설정
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> office[i][j];
            if(0<office[i][j] && office[i][j]<6){
                cctv.push_back({office[i][j], i, j}); // cctv 위치 저장
                dir.push_back(0);
            }
        }
    }
    ans = N*M; 
    solve(0); // cctv로 감시 가능한 영역을 check해가며, 사각 지대의 최소 크기를 구함
    cout << ans;
}