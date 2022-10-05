#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 51
#define INF 987654321
#define VIRUS 0
#define WALL 1
#define HOSPITAL 2
#define NOTVISIT -1
using namespace std;

int N, M, ans=INF;
int virus_num=0;
int map[MAX][MAX], visited[MAX][MAX];
vector<pair<int, int>> hospital, selected_hospital;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j]==HOSPITAL) hospital.push_back({i,j});
            if(map[i][j]==VIRUS) virus_num++;
        }
    }
}

void print_map(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cout << visited[i][j] << " ";
        cout << "\n";
    } cout << "\n";
}

void init_visited(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) visited[i][j] = NOTVISIT;
    }
}

int bfs(){
    init_visited();
    int res=0, num=0; // 바이러스를 전부 없애는데 걸리는 시간 중 최소 시간, 없앤 바이러스 수 
    queue<pair<int, int>> q;

    // 선택한 병원 to queue
    for(int i=0; i<M; i++){
        int y = selected_hospital[i].first;
        int x = selected_hospital[i].second;
        visited[y][x] = 0;
        q.push({y,x});
    }

    // bfs 탐색 시작
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=N || nx<0 || nx>=N || map[ny][nx]==WALL) continue; // 범위를 벗어나는 경우, 벽인 경우 
            if(visited[ny][nx]==NOTVISIT){
                visited[ny][nx] = visited[y][x]+1;
                if(map[ny][nx] == VIRUS) num++;
                q.push({ny,nx});
            }
            else if(visited[y][x]+1 < visited[ny][nx]){
                visited[ny][nx] = visited[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==VIRUS && visited[i][j]!=NOTVISIT) res = max(res, visited[i][j]);
        }
    }
    if(num<virus_num) return INF;
    return res;
}

void solution(int idx, int depth){
    if(depth == M){
        ans = min(ans, bfs());
        return ;
    }
    for(int i=idx; i<(int)hospital.size(); i++){
        selected_hospital.push_back(hospital[i]);
        solution(i+1, depth+1);
        selected_hospital.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution(0, 0);
    if(ans==INF) cout << -1;
    else cout << ans;
}