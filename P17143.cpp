#include<iostream>
#define MAX 101
using namespace std;

struct shark { int speed, direction, size; };

int R, C, M; // 격자판의 크기, 상어의 수
int ans = 0; // 낚시왕이 잡은 상어 크기의 합
shark grid[MAX][MAX], copy_grid[MAX][MAX];

int dr[] = {0, -1, 1, 0, 0}; // d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽
int dc[] = {0, 0, 0, 1, -1};

void move_shark(){
    for(int r=1; r<=R; r++){
        for(int c=1; c<=C; c++){
            if(grid[r][c].size==0) continue; // 상어가 없는 경우
            int nr=r, nc=c;
            int move_cnt = grid[r][c].speed;
            int move_dir = grid[r][c].direction;
            if(move_dir<3) move_cnt%=(2*R-2); // 시간초과 방지
            else move_cnt%=(2*C-2);
            while (move_cnt--){ // 상어가 있는 경우, 상어 이동
                nr+=dr[move_dir]; 
                nc+=dc[move_dir];
                if(nr<1 || nr>R || nc<1 || nc>C){ // 격자를 벗어나는 경우
                    if(move_dir==1 || move_dir==3) move_dir++; // 방향을 바꿈
                    else move_dir--; // 방향을 바꿈
                    nr+=dr[move_dir]*2; // 바꾼 방향으로 제대로 이동 
                    nc+=dc[move_dir]*2;
                }
            }
            grid[r][c].direction = move_dir; // 바뀐 방향 저장 !!!!!!!
            if(copy_grid[nr][nc].size==0) // 이동을 마친 곳에 다른 상어가 없는 경우
                copy_grid[nr][nc] = grid[r][c];
            else if(copy_grid[nr][nc].size < grid[r][c].size) // 다른 상어가 있는 경우, 큰 상어가 나머지 상어를 잡아 먹음
                copy_grid[nr][nc] = grid[r][c];
        }
    }
    for(int r=1; r<=R; r++){ 
        for(int c=1; c<=C; c++){
            grid[r][c] = copy_grid[r][c]; // copy_gird -> gird 복제
            copy_grid[r][c] = {0,0,0}; // 초기화
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> M;
    int r, c, s, d, z; // 상어의 정보 (위치, 속력, 이동 방향, 크기)
    while (M--){
        cin >> r >> c >> s >> d >> z;
        grid[r][c] = {s, d, z};
    }
    for(int i=1; i<=C; i++){ // 1. 낚시왕이 오른쪽으로 한 칸씩 이동
        for(int j=1; j<=R; j++){
            if(grid[j][i].size==0) continue; // 상어가 없는 경우
            ans+=grid[j][i].size; // 2. 낚시왕이 땅과 제일 가까운 상어를 잡음
            // cout << i << ' ' << grid[j][i].size << '\n';
            grid[j][i] = {0,0,0}; // 상어를 잡았으므로 비워줌
            break;
        }
        move_shark(); // 3. 상어 이동
    }
    cout << ans;
}