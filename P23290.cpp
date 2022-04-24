#include<iostream>
#include<vector>
#define SIZE 5
#define MOVE 3
using namespace std;

int M, S;
int sy, sx, maxEat;
int smell[SIZE][SIZE];
bool visit[SIZE][SIZE];
int way[MOVE]={0}, copyWay[MOVE]={0};
vector<int> map[SIZE][SIZE], copyMap[SIZE][SIZE];

int sdy[] = {-1, 1, 0, 0}; // 상 하 좌 우 (상어 방향)
int sdx[] = {0, 0, -1, 1};
int fdy[] = {0, -1, -1, -1, 0, 1, 1, 1}; // ←, ↖, ↑, ↗, →, ↘, ↓, ↙ (물고기 방향)
int fdx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void copyFish(){ // 물고기 복제 시작
    for(int i=1; i<SIZE; i++){
        for(int j=1; j<SIZE; j++)
            copyMap[i][j] = map[i][j];
    }
}

void moveFish(){ // 물고기 이동 
    vector<int> moveMap[SIZE][SIZE];
    for(int i=1; i<SIZE; i++){
        for(int j=1; j<SIZE; j++){
            for(int k=0; k<map[i][j].size(); k++){
                int dir = map[i][j][k];
                bool ismove = false; // 이동 가능 여부
                for(int d=0; d<8; d++){
                    int ny = i+fdy[dir];
                    int nx = j+fdx[dir];
                    dir--; if(dir<0) dir = 7; // 반시계 방향 회전
                    if(ny<1 || ny>4 || nx<1 || nx>4 || smell[ny][nx] || ny==sy&&nx==sx) continue; // 범위를 벗어나는 경우, 냄새가 있는 경우, 상어가 있는 경우
                    ismove = true; // 이동 가능
                    dir++; if(dir>7) dir=0;
                    moveMap[ny][nx].push_back(dir);
                    break;
                }
                if(!ismove){
                    dir--; if(dir<0) dir = 7; 
                    moveMap[i][j].push_back(dir);
                }
            }
        }
    }
    for(int i=1; i<SIZE; i++){
        for(int j=1; j<SIZE; j++) map[i][j] = moveMap[i][j];
    }
}

void findWay(int y, int x, int eat, int cnt){ // 상어의 이동동선을 찾음
    if(cnt==3){ // 이동 3번이 마무리 된 경우
        if(maxEat<eat){
            maxEat = eat;
            for(int i=0; i<MOVE; i++)
                way[i] = copyWay[i];
        }
        return;
    }
    int ny, nx;
    for(int d=0; d<4; d++){
        ny = y+sdy[d];
        nx = x+sdx[d];
        if(ny<1 || ny>4 || nx<1 || nx>4) continue; // 범위를 벗어나는 경우
        copyWay[cnt] = d;
        if(visit[ny][nx]) continue;
        visit[ny][nx] = true;
        findWay(ny, nx, eat+map[ny][nx].size(), cnt+1);
        visit[ny][nx] = false;
    }
}

void moveShark(){ // 상어 이동
    int y=sy, x=sx;
    for(int i=0; i<MOVE; i++){
        y+=sdy[way[i]];
        x+=sdx[way[i]];
        if(map[y][x].size()) smell[y][x] = 3;
        map[y][x].clear();
        sy=y; sx=x;
    }
}

void removeSmell(){ // 물고기 냄세 제거
    for(int i=1; i<SIZE; i++){
        for(int j=1; j<SIZE; j++){
            if(smell[i][j]>0) smell[i][j]--;
        }
    }
}

void finshCopy(){ // 물고기 복제 완료
    for(int i=1; i<SIZE; i++){
        for(int j=1; j<SIZE; j++){
            for(int k=0; k<copyMap[i][j].size(); k++){
                map[i][j].push_back(copyMap[i][j][k]);
            }
            copyMap[i][j].clear();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> S;
    int fy, fx, d, ans=0;
    for(int i=0; i<M; i++){
        cin >> fy >> fx >> d;
        map[fy][fx].push_back(d-1);
    }
    cin >> sy >> sx; // 상어 위치
    while (S--){
        copyFish(); // 물고기 복제 시작
        moveFish(); // 물고기 이동
        maxEat = -1;
        findWay(sy, sx, 0, 0); // 물고기를 가장 많이 잡아먹을 수 있는 이동 동선을 찾음
        moveShark(); // 상어 이동
        removeSmell(); // 물고기 냄세 제거
        finshCopy(); // 물고기 복제 완료
    }
    for(int i=1; i<SIZE; i++){
        for(int j=1; j<SIZE; j++)
            ans+=map[i][j].size();
    }
    cout << ans;
}