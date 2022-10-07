#include<iostream>
#include<queue>
#define MAX 65
using namespace std;

int N, Q, n;
bool visited[MAX][MAX];
int map[MAX][MAX], tmp_map[MAX][MAX];
int pown[] = {1, 2, 4, 8, 16, 32, 64};
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void add_and_init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            map[i][j]+=tmp_map[i][j];
            tmp_map[i][j] = 0;
        }
    }
}

void copy_and_init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            map[i][j] = tmp_map[i][j];
            tmp_map[i][j] = 0;
        }
    }
}

void rotate_ice(int L){
    int criteria = pown[L]; // 기준 
    for(int y=0; y<n; y+=criteria){
        for(int x=0; x<n; x+=criteria){
            // 빙하의 특정 범위를 시계방향으로 회전 
            for(int i=0; i<criteria; i++){
                for(int j=0; j<criteria; j++) tmp_map[y+j][x+criteria-i-1] = map[y+i][x+j];
            }
        }
    } copy_and_init();
}

void melt_ice(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!map[i][j]) continue; // 얼음이 없는 경우
            int cnt = 0;
            for(int d=0; d<4; d++){
                int ny = i+dy[d];
                int nx = j+dx[d];
                if(ny<0 || ny>=n || nx<0 || nx>=n || !map[ny][nx]) continue; // 범위를 벗어나거나, 얼음이 없는 경우 
                cnt++;
            }
            if(cnt<3) tmp_map[i][j] = -1; // 얼음 녹음 (인접한 칸에 얼음이 3개 이상 있지 않은 경우 )
        }
    } add_and_init();
}

void input(){
    cin >> N >> Q; n = pown[N];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
    while(Q--){
        int L; cin >> L;
        rotate_ice(L);
        melt_ice();
    }
}

int bfs(int i, int j){
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({i,j});

    int res = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue; // 범위를 벗어나는 경우 
            if(!map[ny][nx] || visited[ny][nx]) continue; // 얼음이 없거나, 이미 방문한 경우 
            visited[ny][nx] = true;
            q.push({ny,nx});
            res++;
        }
    }
    return res;
}

void output(){
    int remain=0;
    int cluster=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            remain+=map[i][j];
            if(!visited[i][j] && map[i][j]) cluster = max(cluster, bfs(i,j));
        }
    } cout << remain << "\n" << cluster;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    output();
}