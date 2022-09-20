#include <iostream>
#define MAX 101
using namespace std;

int N, M, Q;
int r1, c1, r2, c2;
int map[MAX][MAX], tmp_map[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(){
    cin >> N >> M >> Q;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) cin >> map[i][j];
    }
}

void copy(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) tmp_map[i][j] = map[i][j];
    }
}

void rotate(){
    int tmp = map[r1][c2];
    for(int col=c2; col>c1; col--) map[r1][col] = map[r1][col-1]; // up
    for(int row=r1; row<r2; row++) map[row][c1] = map[row+1][c1]; // left
    for(int col=c1; col<c2; col++) map[r2][col] = map[r2][col+1]; // down
    for(int row=r2; row>r1; row--) map[row][c2] = map[row-1][c2]; // right
    map[r1+1][c2] = tmp;
}

void change(){
    copy();
    for(int r=r1; r<=r2; r++){
        for(int c=c1; c<=c2; c++){
            int cnt = 1;
            int total= tmp_map[r][c];
            for(int d=0; d<4; d++){
                int nr = r+dr[d];
                int nc = c+dc[d];
                if(nr<1 || nr>N || nc<1 || nc>M) continue;
                cnt++;
                total+=tmp_map[nr][nc];
            }
            map[r][c] = total/cnt;
        }
    }
}

void solution(){
    while(Q--){
        cin >> r1 >> c1 >> r2 >> c2;
        rotate();
        change();
    }
}

void output(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) cout << map[i][j] << " ";
        cout <<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}