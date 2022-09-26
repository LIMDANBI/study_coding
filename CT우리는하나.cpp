#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 9
using namespace std;

int n, k, u, d, ans=0;
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int,int>> pos, s_pos;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> n >> k >> u >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            pos.push_back({i,j});
        }
    }
}

int bfs(){
    int y, x, ny, nx, diff, res=0;
    memset(visited, false, sizeof(visited)); // 초기화

    queue<pair<int, int>> q;
    for(int i=0; i<k; i++){ // 선택한 k개의 도시
        y = s_pos[i].first;
        x = s_pos[i].second;
        visited[y][x] = true;
        q.push({y,x}); res++;
    }
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int dir=0; dir<4; dir++){
            ny = y+dy[dir];
            nx = x+dx[dir];
            if(ny<0 || ny>=n || nx<0 || nx>=n || visited[ny][nx]) continue; // 범위를 벗어나는 경우, 이미 방문한 경우
            diff = abs(map[y][x]-map[ny][nx]); // 두 도시간 높이의 차
            if(u<=diff && diff<=d){ // 두 도시간 높이의 차가 u 이상 d 이하인 경우에만 이동 가능
                visited[ny][nx] = true;
                q.push({ny, nx}); res++;
            }
        }
    }
    return res;
}

void solution(int idx, int cnt){ // k개의 도시를 적절하게 골라 갈 수 있는 서로 다른 도시의 수를 최대로 하는 프로그램
    if(cnt==k){
        ans = max(ans, bfs());
        return;
    }
    for(int i=idx; i<(int)pos.size(); i++){
        s_pos.push_back(pos[i]);
        solution(idx+1, cnt+1);
        s_pos.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution(0, 0);
    cout << ans;
}