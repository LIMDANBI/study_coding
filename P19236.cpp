#include<iostream>
#define MAX 5
#define SHARK -1
#define FISHNUM 17
using namespace std;

struct FISH{
    int y, x, d;
    bool isdead=false;
};

int ans = 0;
int sy=1, sx=1, sd;
FISH fish[FISHNUM];
int map[MAX][MAX];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}; // ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

void printMap(){
    for(int i=1; i<MAX; i++){
        for(int j=1; j<MAX; j++){
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }
}

void moveFish(){ // 물고기 이동
    for(int num=1; num<FISHNUM; num++){ // 번호가 작은 물고기부터 순서대로 이동
        if(fish[num].isdead) continue;
        int y = fish[num].y;
        int x = fish[num].x;
        int d = fish[num].d;
        for(int i=d; i<d+8; i++){ // 반시계 방향으로 회전해가며
            int dir=i; dir%=8;
            int ny = y+dy[dir];
            int nx = x+dx[dir];
            if(ny<1 || ny>4 || nx<1 || nx>4 || map[ny][nx]==SHARK) continue; // 범위를 벗어나는 경우, 상어가 있는 경우
            
            // map에서 물고기 위치를 교환 
            int tmp = map[ny][nx];
            map[ny][nx] = map[y][x];
            map[y][x] = tmp; 
            
            // fish 정보 수정
            fish[num].y = ny;
            fish[num].x = nx;
            fish[num].d = dir;
            fish[tmp].y = y;
            fish[tmp].x = x;
            break;
        }
    }
}

void moveShark(int y, int x, int d, int eat){ // 상어 이동
    ans = max(ans, eat);
    int copyMap[MAX][MAX];
    FISH copyFish[FISHNUM];
    for(int i=1; i<MAX; i++){ // map 복사
        for(int j=1; j<MAX; j++) copyMap[i][j] = map[i][j];
    }
    for(int i=1; i<FISHNUM; i++) copyFish[i] = fish[i]; // 물고기 정보 복사
    moveFish(); // 물고기 이동
    for(int mul=1; mul<4; mul++){ // 상어 이동
        int ny = y+dy[d]*mul;
        int nx = x+dx[d]*mul;
        if(ny<1 || ny>4 || nx<1 || nx>4) continue;
        if(map[ny][nx]==0) continue;
        int fishNum = map[ny][nx];
        map[y][x]=0; map[ny][nx]=SHARK; fish[fishNum].isdead = true;
        moveShark(ny, nx, fish[fishNum].d, eat+fishNum);
        map[y][x]=SHARK; map[ny][nx]=fishNum; fish[fishNum].isdead = false;
    }
    for(int i=1; i<MAX; i++){ // map 복구
        for(int j=1; j<MAX; j++) map[i][j] = copyMap[i][j];
    }
    for(int i=1; i<FISHNUM; i++) fish[i] = copyFish[i]; // 물고기 정보 복구
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, eat=0;
    for(int i=1; i<MAX; i++){
        for(int j=1; j<MAX; j++){
            cin >> a >> b; // 물고기 번호, 방향
            map[i][j] = a;
            fish[a].y = i;
            fish[a].x = j;
            fish[a].d = b-1;
        }
    }
    sd = fish[map[1][1]].d;
    fish[map[1][1]].isdead = true;
    eat = map[1][1];
    map[1][1] = SHARK;
    moveShark(sy, sx, sd, eat); // moveFish() 포함
    cout << ans;
}