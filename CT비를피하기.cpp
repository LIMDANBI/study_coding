#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
#define WALL 1
#define PERSON 2
#define SPACE 3
using namespace std;

int n, h, m;
int map[MAX][MAX];
int ans[MAX][MAX];
int minTime[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> pos;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> n >> h >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j]==PERSON) pos.push_back({i,j}); // 사람의 위치
        }
    }
}

int bfs(int i, int j){
    memset(minTime, 0, sizeof(minTime));
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    int res = -1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue; // 범위를 벗어나는 경우
            if(map[ny][nx]==WALL || visited[ny][nx]) continue; // 벽인거나 이미 방문한 경우
            if(map[ny][nx]==SPACE) return minTime[y][x]+1; // 비를 피할 수 있는 곳에 도착
            minTime[ny][nx] = minTime[y][x]+1;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    return res;
}

void solution(){ // 각 사람마다 비를 피할 수 있는 가장 가까운 공간까지의 거리를 구하는 프로그램
    for(int i=0; i<pos.size(); i++){
        int y = pos[i].first;
        int x = pos[i].second;
        ans[y][x] = bfs(y, x);
    }
}

void output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) 
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}