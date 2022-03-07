#include<iostream>
#include<vector>
#include<queue>
#define MAX 50
using namespace std;

int R, C, T, ans=0;
int room[MAX][MAX];
int spreadRoom[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int upcleaner=0, downcleaner=0;

void spread(){ // 미세 먼지 확산
    queue<pair<int, int> > dust;
    for(int i=0; i<R; i++){ // 미세 먼지 위치 저장
        for(int j=0; j<C; j++){
            if(room[i][j]>0) dust.push({i,j});
        }
    }
    while (!dust.empty()){
        int r = dust.front().first;
        int c = dust.front().second;
        dust.pop();
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0 || nr>=R || nc<0 || nc>=C) continue; // 범위를 벗어나는 경우 
            if(room[nr][nc]==-1) continue; // 공기 청정기가 있는 경우
            spreadRoom[nr][nc]+=(room[r][c]/5); // 미세먼지 확산
            spreadRoom[r][c]-=(room[r][c]/5); // 미세먼지 확산 후 남은 미세먼지는 줄어듦
        }
    }
    for(int i=0; i<R; i++){ // 배열 복사
        for(int j=0; j<C; j++) {
            room[i][j]+=spreadRoom[i][j];
            spreadRoom[i][j] = 0;
        }
    }
}

void clean(){ // 공기 청정기 동작
    
    // 위쪽 공기청정기의 바람 - 반시계방향으로 순환
    int r = upcleaner;
    for(int i=r-1; i>0; i--) room[i][0] = room[i-1][0];
    for(int i=0; i<C-1; i++) room[0][i] = room[0][i+1];
    for(int i=0; i<r; i++) room[i][C-1] = room[i+1][C-1];
    for(int i=C-1; i>1; i--) room[r][i] = room[r][i-1];
    room[r][1] = 0;

    // 아래쪽 공기청정기의 바람 - 시계방향으로 순환
    r = downcleaner;
    for(int i=r+1; i<R-1; i++) room[i][0] = room[i+1][0];
    for(int i=0; i<C-1; i++) room[R-1][i] = room[R-1][i+1];
    for(int i=R-1; i>r; i--) room[i][C-1] = room[i-1][C-1];
    for(int i=C-1; i>1; i--) room[r][i] = room[r][i-1];
    room[r][1] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> room[i][j];
            if(room[i][j]==-1){
                if(upcleaner) downcleaner = i;
                else upcleaner = i;
            }
        }
    }
    while (T--){ // T초 동안
        spread(); // 미세 먼지 확산
        clean(); // 공기 청정기 동작
    }
    for(int i=0; i<R; i++){ // T초가 지난 후 구사과 방에 남아있는 미세먼지의 양
        for(int j=0; j<C; j++) {
            if(room[i][j]>0) ans+=room[i][j];
        }
    }
    cout << ans;
}