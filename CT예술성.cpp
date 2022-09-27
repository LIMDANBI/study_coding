#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 30
using namespace std;

struct GROUP{int id, num, size, y, x;};
vector<GROUP> group, selected;

int n, ans=0, group_id=1;
int map[MAX][MAX], group_map[MAX][MAX];
bool visited[MAX][MAX], tmp_visited[MAX][MAX];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void init(){
    group_id = 1;
    group.clear();
    memset(visited, false, sizeof(visited));
}

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
}

int contactline(int i, int j, int other_group_id){
    memset(tmp_visited, false, sizeof(tmp_visited));
    queue<pair<int, int>> q;
    tmp_visited[i][j] = true;
    q.push({i,j});

    int res = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=n || tmp_visited[ny][nx]) continue; // 범위를 벗어나는 경우, 이미 방문한 경우 
            if(map[ny][nx]==map[y][x]){
                tmp_visited[ny][nx] = true;
                q.push({ny, nx});
            }
            else if(group_map[ny][nx]==other_group_id) res++;
        }
    }
    return res;
}

void backtracking(int idx, int cnt){
    if(cnt == 2){
        int side = contactline(selected[0].y, selected[0].x, selected[1].id); // 맞닿아 있는 변의 수 
        ans += (selected[0].size + selected[1].size) * selected[0].num * selected[1].num * side;
        return ;
    }
    for(int i=idx; i<group.size(); i++){
        selected.push_back(group[i]);
        backtracking(i+1, cnt+1);
        selected.pop_back();
    }
}

int bfs(int i, int j){ // 해당 그룹의 size를 반환
    queue<pair<int, int>> q; 
    q.push({i,j});
    visited[i][j] = true;
    group_map[i][j] = group_id;
    
    int group_size = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue; // 범위를 벗어나는 경우
            if(visited[ny][nx] || map[ny][nx]!=map[y][x]) continue; // 이미 방문했거나 숫자가 다른 경우
            group_size++;
            q.push({ny,nx});
            visited[ny][nx] = true;
            group_map[ny][nx] = group_id;
        }
    }
    return group_size;
}

void artscore(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue; // 이미 그룹을 가진 경우
            int group_size = bfs(i, j);
            group.push_back({group_id, map[i][j], group_size, i, j});
            group_id++;
        }
    }
    backtracking(0, 0); // 조화로움 값의 합
}

void rotate_square(int y1, int x1, int y2, int x2){
    int tmp = map[y1][x1];
    for(int i=y1; i<y2; i++) map[i][x1] = map[i+1][x1]; // 좌
    for(int i=x1; i<x2; i++) map[y2][i] = map[y2][i+1]; // 하
    for(int i=y2; i>y1; i--) map[i][x2] = map[i-1][x2]; // 우
    for(int i=x2; i>x1; i--) map[y1][i] = map[y1][i-1]; // 상
    map[y1][x1+1] = tmp;
}

void rotate_corss(){
    int mid=n/2, end=n-1, tmp[n];
    for(int i=0; i<mid; i++) tmp[i] = map[i][mid]; // 상 -> tmp
    for(int i=0; i<mid; i++) map[i][mid] = map[mid][end-i]; // 우 -> 상 
    for(int i=0; i<mid; i++) map[mid][end-i] = map[end-i][mid]; // 하 -> 우
    for(int i=0; i<mid; i++) map[end-i][mid] = map[mid][i]; // 좌 -> 하
    for(int i=0; i<mid; i++) map[mid][i] = tmp[i]; // tmp(상) -> 좌
}

void rotation(){
    int start=0, mid=n/2, end=n-1;
    rotate_square(start, start, mid-1, mid-1); // 좌상
    rotate_square(start, mid+1, mid-1, end); // 우상
    rotate_square(mid+1, start, end, mid-1); // 좌하
    rotate_square(mid+1, mid+1, end, end); // 우하
    rotate_corss(); // 십자 모양 회전
}

void solution(){
    artscore();
    for(int i=0; i<3; i++){
        init();
        rotation();
        artscore();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << ans;
}