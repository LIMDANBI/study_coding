#include<iostream>
#define MAX 201
using namespace std;

int n, r, c, map[MAX][MAX], tmp_map[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> map[i][j];
    }
    cin >> r >> c;
}

void solution(){

    // 십자 모양 폭발
    int range = map[r][c];
    map[r][c] = 0;
    for(int d=0; d<4; d++){
        int nr = r, nc = c;
        for(int i=1; i<range; i++){
            nr+=dr[d];
            nc+=dc[d];
            if(nr<1 || nr>n || nc<1 || nc>n) continue; // 범위를 벗어나는 경우
            map[nr][nc] = 0;
        }
    }

    // 중력 작용
    for(int col=1; col<=n; col++){
        int tmp_row = n;
        for(int row=n; row>0; row--){
            if(map[row][col]!=0) {
                tmp_map[tmp_row][col] = map[row][col];
                tmp_row--;
            }
        }
    }
}

void output(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout << tmp_map[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}