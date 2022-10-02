#include<iostream>
#include<cstring>
#define MAX 101
using namespace std;

struct MOLD{int dist, dir, size;};

int n, m, k, ans=0;
MOLD map[MAX][MAX], tmp_map[MAX][MAX];
int dy[] = {0,-1,1,0,0}; // 0 상 하 우 좌
int dx[] = {0,0,0,1,-1};

void input(){
    int y, x, s, d, b;
    cin >> n >> m >> k;
    while(k--){
        cin >> y >> x >> s >> d >> b;
        map[y][x] = {s, d, b}; // 거리, 방향, 크기
    }
}

void copy(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            map[i][j] = tmp_map[i][j];
            tmp_map[i][j] = {0,0,0};
        }
    }
}

void collect_mold(int col){ // 곰팡이 채취
    for(int row=1; row<=n; row++){
        if(map[row][col].size!=0){
            ans+=map[row][col].size;
            map[row][col] = {0,0,0};
            break;
        }
    }
}

void move_mold(){ // 곰팡이 이동
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            if(map[y][x].size==0) continue;
            int dist = map[y][x].dist; // 거리
            int dir = map[y][x].dir; // 방향
            if(dir<3) dist%=(2*n-2); // 시간초과 방지
            else dist%=(2*m-2);

            int ny=y, nx=x;
            while(dist--){
                ny+=dy[dir];
                nx+=dx[dir];
                if(ny<1 || ny>n || nx<1 || nx>m){ // 범위를 벗어나는 경우
                    if(dir==1 || dir==3) dir++;
                    else dir--;
                    ny+=dy[dir]*2;// 잘못 간 만큼 다시 돌려 놓음
                    nx+=dx[dir]*2;
                }
            }
            map[y][x].dir = dir; // 바뀐방향 저장
            if(tmp_map[ny][nx].size==0 || map[y][x].size > tmp_map[ny][nx].size) 
                tmp_map[ny][nx] = map[y][x];
        }
    } copy(); // 이동 중이 아니라 이동 후 겹치는 것에서 비교하기 위해 tmp_ismold 이용
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    for(int col=1; col<=m; col++) { // 해당 격자판에 있는 모든 열 검사
        collect_mold(col);
        move_mold();
    }
    cout << ans; // 인턴이 채취한 곰팡이 크기의 총 합
}