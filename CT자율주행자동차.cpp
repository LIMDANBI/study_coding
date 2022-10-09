#include<iostream>
#define MAX 51
#define SIDEWALK 1
using namespace std;

int n, m;
int ans = 1;
int cy, cx, cd;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = {-1, 0, 1, 0}; // 북 동 남 서 
int dx[] = {0, 1, 0, -1};

void input(){
    cin >> n >> m;
    cin >> cy >> cx >> cd;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> map[i][j];
    }
}

void solution(){
    visited[cy][cx] = true;
    while(1){
        bool is_possible = false;
        int ny=cy, nx=cx, nd=cd;
        for(int d=0; d<4; d++){
            nd = (nd-1+4)%4; // 좌회전
            ny=cy+dy[nd];
            nx=cx+dx[nd];
            if(map[ny][nx]==SIDEWALK || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            is_possible = true;
            cy = ny; cx = nx; cd = nd;
            ans++;
            break;
        }
        if(!is_possible){ // 4방향 모두 확인하였으나 전진하지 못한 경우
            nd = (cd+2)%4; // 방향 유지해서 후진
            ny = cy + dy[nd];
            nx = cx + dx[nd];
            if(map[ny][nx]==SIDEWALK) break;
            cy = ny;
            cx = nx;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << ans;   
}