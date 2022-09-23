#include<iostream>
#define MAX 101
using namespace std;

int n;
int block_num, block_size, max_block_size=0;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
}

void dfs(int y, int x, int num){
    if(y<0 || y>=n || x<0 || x>=n) return;
    if(visited[y][x] || map[y][x]!=num) return;
    visited[y][x] = true;
    block_size++;
    for(int d=0; d<4; d++) dfs(y+dy[d], x+dx[d], num);
}

void solution(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;
            block_size = 0;
            dfs(i, j, map[i][j]);
            if(block_size>3) block_num++; // 터지게 되는 블럭의 수
            max_block_size = max(max_block_size, block_size); // 최대 블럭의 크기
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << block_num << " " << max_block_size;
}
