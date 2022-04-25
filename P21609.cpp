#include<iostream>
#include<cstring>
#include<queue>
#define MAX 21
#define EMPTY -2
#define BLACK -1
#define RAINBOW 0
using namespace std;

int N, M, ans=0;
bool isPlay = true;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct POS { int y, x; };
struct GROUP { int cnt, y, x; };
struct compare{
    bool operator()(const GROUP& g1, const GROUP& g2) { // operator() 메서드 재정의
        if(g1.cnt == g2.cnt){
            if(g1.y == g2.y) return g1.x < g2.x;
            return g1.y < g2.y;
        }
		return g1.cnt < g2.cnt;
	}
};
priority_queue<GROUP, vector<GROUP>, compare> blockGroup; // 기준 block

void init(){
    memset(visit, false, sizeof(visit));
    while(!blockGroup.empty()) blockGroup.pop();
}

int findGroup(int i, int j, int color){
    int groupSize=1;
    queue<POS> q;
    visit[i][j] = true;
    q.push({i, j});
    while (!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny<1 || ny>N || nx<1 || nx>N) continue; // 범위를 벗어나는 경우
            if(map[ny][nx]==EMPTY || visit[ny][nx]) continue; // 비어 있거나, 이미 방문한 경우
            if(map[ny][nx]==BLACK || map[ny][nx]!=RAINBOW && map[ny][nx]!=color) continue; // black block이거나 다른 색인 경우 (무지개는 허용)
            visit[ny][nx] = true; // 방문
            groupSize++;
            q.push({ny, nx});
        }
    }
    return groupSize;
}

void rmeoveGroup(){
    queue<POS> q;
    int cnt = blockGroup.top().cnt;
    ans+=cnt*cnt; //  B^2점을 획득
    int y = blockGroup.top().y;
    int x = blockGroup.top().x;
    int color=map[y][x];
    map[y][x] = EMPTY;
    visit[y][x] = true;
    q.push({y, x});
    while (!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny<1 || ny>N || nx<1 || nx>N) continue; // 범위를 벗어나는 경우
            if(map[ny][nx]==EMPTY || visit[ny][nx]) continue; // 비어 있거나, 이미 방문한 경우
            if(map[ny][nx]==BLACK || map[ny][nx]!=RAINBOW && map[ny][nx]!=color) continue; // black block이거나 다른 색인 경우 (무지개는 허용)
            visit[ny][nx] = true;
            map[ny][nx] = EMPTY;
            q.push({ny, nx});
        }
    }
}

void gravityAction(){ // 격자에 중력 작용
    for(int j=1; j<=N; j++){
        for(int i=N; i>0; i--){
            if(map[i][j]!=EMPTY) continue;
            int y = i;
            while(y>1 && map[y][j]==EMPTY) y--;
            if(map[y][j]==BLACK) continue;
            map[i][j] = map[y][j];
            map[y][j] = EMPTY;
        }
    }
}

void counterclockwiseRotation(){ // 반시계 방향으로 90도 회전
    queue<int> q;
    for(int i=1; i<=N; i++){
        for(int j=N; j>0; j--) q.push(map[i][j]);
    }
    for(int j=1; j<=N; j++){
        for(int i=1; i<=N; i++){
            map[i][j] = q.front();
            q.pop();
        }
    }
}


void autoPlay(){ // 블록 그룹이 존재하는 동안 반복
    init(); // 초기화
    for(int i=1; i<=N; i++){ // 블록 그룹 정보 저장
        for(int j=1; j<=N; j++){
            if(map[i][j]==BLACK || map[i][j]==RAINBOW || map[i][j]==EMPTY || visit[i][j]) continue;
            int cnt = findGroup(i, j, map[i][j]); // BFS로 group check
            if(cnt>=2) blockGroup.push({cnt, i, j}); // 기준 block을 pq에 저장 (그룹에 속한 블록의 개수는 2보다 크거나 같아야 함)
        }
    }
    if(blockGroup.size()==0){
        isPlay = false;
        return ;
    }
    memset(visit, false, sizeof(visit));
    rmeoveGroup(); // 찾은 블록 그룹의 모든 블록 제거
    gravityAction(); // 격자에 중력 작용
    counterclockwiseRotation(); // 격자가 90도 반시계 방향으로 회전
    gravityAction(); // 격자에 중력 작용
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cin >> map[i][j];
    }
    while(isPlay) autoPlay(); // 블록 그룹이 존재하는 동안 반복
    cout << ans;
}