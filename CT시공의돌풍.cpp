#include<iostream>
#include<cstring>
#define MAX 51
using namespace std;

int n, m, t;
int hy=-1, hx=-1; // 시공의 돌품
int map[MAX][MAX], tmp_map[MAX][MAX];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(hy==-1 && map[i][j]==-1){
                hy = i;
                hx = j;
            }
        }
    }
}

void add_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) map[i][j]+=tmp_map[i][j];    
    }
    memset(tmp_map, 0, sizeof(tmp_map));
}

void move_dust(){
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(map[y][x]==-1) continue; // 시공의 돌풍 위치인 경우
            int dust = map[y][x]/5; // 확산될 먼지의 양
            for(int d=0; d<4; d++){
                int ny=y+dy[d];
                int nx=x+dx[d];
                if(ny<0 || ny>=n || nx<0 || nx>=m || map[ny][nx]==-1) continue;
                tmp_map[ny][nx]+=dust; // 먼지의 확산
                tmp_map[y][x]-=dust; // 각 칸에 확산될 때마다 원래 칸의 먼지의 양은 확산된 먼지만큼 줄어듦
            }
        }
    }
    add_map();
}

void start_clean(){

    // 상 - 시계 방향
    for(int i=hy-1; i>0; i--) map[i][0]= map[i-1][0]; // 좌
    for(int i=0; i<m-1 ; i++) map[0][i] = map[0][i+1]; // 상 
    for(int i=0; i<hy ; i++) map[i][m-1] = map[i+1][m-1]; // 우
    for(int i=m-1; i>0; i--) map[hy][i] = map[hy][i-1]; // 하
    map[hy][hx+1] = 0;

    // 하 - 반시계 방향
    for(int i=hy+2; i<n-1; i++) map[i][0] = map[i+1][0]; // 좌 
    for(int i=0; i<m-1; i++) map[n-1][i] = map[n-1][i+1]; // 하 
    for(int i=n-1; i>hy+1; i--) map[i][m-1] = map[i-1][m-1]; // 우 
    for(int i=m-1; i>0; i--) map[hy+1][i] = map[hy+1][i-1]; // 상
    map[hy+1][hx+1] = 0;
}

void output(){ // t초가 지난 이후 방에 남아있는 먼지의 양
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) ans+=map[i][j];
    }
    cout << ans+2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    while(t--){
        move_dust();
        start_clean();
    }
    output();
}