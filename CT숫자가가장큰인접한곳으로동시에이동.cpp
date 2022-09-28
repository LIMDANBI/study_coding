#include<iostream>
#include<cstring>
#define MAX 21
using namespace std;

int n, m, t, ans;
int map[MAX][MAX];
int bead[MAX][MAX], tmp_bead[MAX][MAX];

int dy[] = {-1,1,0,0}; // 상하좌우
int dx[] = {0,0,-1,1};

void input(){
    int r, c;
    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
    for(int i=0; i<m; i++){
        cin >> r >> c;
        bead[r-1][c-1] = 1;
    }
}

void solution(){
    memset(tmp_bead, 0, sizeof(tmp_bead));
    ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(bead[i][j]!=1) continue;

            int maxval=0, dir=-1;
            for(int d=0; d<4; d++){
                int ny = i+dy[d];
                int nx = j+dx[d];
                if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if(maxval<map[ny][nx]){ // 숫자가 가장 큰 인접한 곳을 찾음
                    maxval = map[ny][nx];
                    dir = d;
                }
            }
            int y = i+dy[dir];
            int x = j+dx[dir];
            tmp_bead[y][x]++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            if(tmp_bead[i][j]>1) bead[i][j] = 0; // 2개 이상의 구슬 위치가 동일하다면, 해당 위치에 있는 구슬들은 전부 사라짐
            else bead[i][j] = tmp_bead[i][j];
            if(bead[i][j]==1) ans++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    while(t--) solution();
    cout << ans;
}