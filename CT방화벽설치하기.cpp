#include<iostream>
#include<queue>
#define MAX 8
#define FIRE 2
#define WALL 1
#define EMPTY 0
using namespace std;

int n, m;
int ans = 0;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> map[i][j];
    }
}

void copy_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) tmp_map[i][j] = map[i][j];
    }
}

int bfs(){
    queue<pair<int, int>> q;
    copy_map();
    for(int i=0; i<n; i++){ // 불의 위치 
        for(int j=0; j<m; j++){
            if(tmp_map[i][j]==FIRE) q.push({i,j});
        }
    }

    // 불이 퍼짐
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(tmp_map[ny][nx]==EMPTY){
                tmp_map[ny][nx] = FIRE;
                q.push({ny, nx});
            }
        }
    }

    // 방화벽을 제외하고 불이 퍼지지 않은 영역의 크기를 구함 
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp_map[i][j]==EMPTY) res++;
        }
    }
    return res;
}

void solution(int cnt){
    if(cnt==3){ // 방화벽 3개를 추가로 설치한 경우 
        ans = max(ans, bfs());
        return ;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]==EMPTY){
                map[i][j] = WALL;
                solution(cnt+1);
                map[i][j] = EMPTY;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution(0);
    cout << ans;
}