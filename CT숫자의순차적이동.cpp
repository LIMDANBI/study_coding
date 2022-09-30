#include<iostream>
#include<vector>
#define MAX 21
using namespace std;

int n, m, map[MAX][MAX];
vector<pair<int, int>> pos(MAX);
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
            pos[map[i][j]-1] = {i,j};
        }
    }
}

void solution(){
    int y, x, ny, nx;
    int max_val, max_dir;
    int tmp, max_dir_y, max_dir_x;
    for(int i=0; i<n*n; i++){
        y = pos[i].first;
        x = pos[i].second;
        max_val = 0;
        for(int d=0; d<8; d++){
            ny = y+dy[d];
            nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue; // 범위를 벗어나는 경우 
            if(max_val<map[ny][nx]){ // 인접한 숫자들 중 가장 큰 값을 찾음
                max_val = map[ny][nx];
                max_dir = d;
            }
        }
        max_dir_y = y+dy[max_dir];
        max_dir_x = x+dx[max_dir];
        tmp = map[y][x];
        map[y][x] = map[max_dir_y][max_dir_x];
        map[max_dir_y][max_dir_x] = tmp;
        pos[map[y][x]-1] = {y, x}; // 바뀐 위치도 같이 기록해주기!!!!
        pos[i] = {max_dir_y, max_dir_x};
    }
}

void output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << map[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    while(m--) solution();
    output();
}