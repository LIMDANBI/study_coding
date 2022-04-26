#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX 51
#define MAXVIRUS 10 // 놓을 수 있는 바이러스 최대 개수
#define EMPTY 0 // 빈칸
#define WALL 1 // 벽
#define VIRUS 2 // 바이러스를 놓을 수 있는 위치
using namespace std;

struct POS{int y, x;};
vector<POS> Virus;

int N, M;
int empty_cnt, ans=INF;
bool Active[MAXVIRUS];
int Map[MAX][MAX], Time[MAX][MAX];
int Dy[] = {-1, 1, 0, 0};
int Dx[] = {0, 0, -1, 1};

void spredVirus(queue<POS> Queue){
    int time=0, infect_cnt=0; // 걸린 시간, 감염된 칸
    while (!Q.empty()){
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();
        for(int d=0; d<4; d++){
            int ny = y + Dy[d];
            int nx = x + Dx[d];
            if(ny<1 || ny>N || nx<1 || nx>N || Map[ny][nx]==WALL || Time[ny][nx]!=-1) continue; // 범위를 벗어나는 경우, 벽인 경우, 이미 방문한 경우
            Time[nx][ny] = Time[x][y]+1;
            if(Map[ny][nx]!=VIRUS){
                infect_cnt++;
                time = Time[nx][ny];
            }
            Q.push({ny, nx});
        }
    }
    if(infect_cnt==empty_cnt) ans = min(time, ans);
}

void setVirus(int idx, int cnt){ // backtracking 
    if(cnt==M){
        queue<POS> Q;
        memset(Time, -1, sizeof(Time));
        for(int i=0; i<Virus.size(); i++){
            if(Active[i]){
                int y = Virus[i].y;
                int x = Virus[i].x;
                Time[y][x] = 0;
                Q.push({y, x});
            }
        }
        spredVirus(Q);
        return ;
    }
    for(int i=idx; i<Virus.size(); i++){
        if(Active[i]) continue;
        Active[i] = true;
        setVirus(idx+1, cnt+1);
        Active[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) {
            cin >> Map[i][j];
            if(Map[i][j]==EMPTY) empty_cnt++; // 빈 공간 count -> 나중에 모두 
            if(Map[i][j]==VIRUS) Virus.push_back({i, j});
        }
    }
    setVirus(0, 0);
    if(ans==INF) cout << -1;
    else cout << ans;
}