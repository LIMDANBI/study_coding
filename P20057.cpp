#include<iostream>
#define MAX 500
using namespace std;

int N, ans=0;
int A[MAX][MAX];

int tr[] = {0, 1, 0, -1}; // 좌 하 우 상 (토네이도 이동)
int tc[] = {-1, 0, 1, 0};
int percent[] = { 1, 1, 7, 7, 10, 10, 2, 2, 5};
int sr[4][9] = {{-1, 1, -1, 1, -1, 1, -2, 2, 0}, // 좌
                {-1, -1, 0, 0, 1, 1, 0, 0, 2}, // 하
                {-1, 1, -1, 1, -1, 1, -2, 2, 0 }, // 우
                {1, 1, 0, 0, -1, -1, 0, 0, -2 }}; // 상
int sc[4][9] = {{1, 1, 0, 0, -1, -1, 0, 0, -2},
                {-1, 1, -1, 1, -1, 1, -2, 2, 0},
                {-1, -1, 0, 0, 1, 1, 0, 0, 2},
                {-1, 1, -1, 1, -1, 1, -2, 2, 0}};

void move_sand(int r, int c, int d){ // 방향에 따른 모래 이동
    int Arc = A[r][c], nr, nc, move_sand_amout;
    for(int s=0; s<9; s++){
        nr = r+sr[d][s];
        nc = c+sc[d][s];
        move_sand_amout = (Arc*percent[s])/100;
        A[r][c]-=move_sand_amout; // 흩날린 만큼 감소
        if(nr<1 || nr>N || nc<1 || nc>N) ans+=move_sand_amout; // 격자 밖으로 이동하는 경우
        else A[nr][nc]+=move_sand_amout; // 격자 내부에서 이동하는 경우
    }
    nr = r+tr[d]; nc = c+tc[d]; // y의 모든 모래가 비율과 α가 적혀있는 칸으로 이동
    if(nr<1 || nr>N || nc<1 || nc>N){ // 격자 밖으로 이동하는 경우
        ans+=A[r][c];
        A[r][c] = 0;
    }
    else{ // 격자 내부에서 이동하는 경우
        A[nr][nc]+=A[r][c];
        A[r][c] = 0;
    }
}

void tornado(){
    int r=N/2+1, c=N/2+1; // 토네이도의 위치
    int step=0; // 해당 방향으로 몇칸 이동하는지
    for(int i=0; i<N/2; i++){ // N/2 만큼 '좌하우상' 반복
        for(int d=0; d<4; d++){
            if(d%2==0) step++;
            for(int t=0; t<step; t++){ // 토네이도 이동
                r+=tr[d]; c+=tc[d];
                move_sand(r, c, d); // 모래 이동
            }
        }
    }
    for(int t=0; t<step; t++){ // 마지막 '좌' 방향 이동 <(1, 1)까지 이동한 뒤 소멸>
        r+=tr[0]; c+=tc[0];
        move_sand(r, c, 0);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cin >> A[i][j]; // 격자의 각 칸에 있는 모래
    }
    tornado(); // 토네이도 시전
    cout << ans; // 토네이도가 소멸되었을 때, 격자의 밖으로 나간 모래의 양
}