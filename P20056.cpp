#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

struct FIREBALL{int m, s, d;};
vector<FIREBALL> map[MAX][MAX];

int N, M, K, ans=0;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}; // ↑, ↗, →, ↘, ↓, ↙, ←, ↖,
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void moveFireball(){
    vector<FIREBALL> tmpMap[MAX][MAX];
    for(int i=1; i<=N; i++){ // 모든 파이어볼이 자신의 방향 d로 속력 s칸 만큼 이동
        for(int j=1; j<=N; j++){
            for(int k=0; k<map[i][j].size(); k++){
                int m = map[i][j][k].m; // 질량
                int s = map[i][j][k].s; // 속력
                int d = map[i][j][k].d; // 방향
                int ny = i+dy[d]*s;
                int nx = j+dx[d]*s;
                if(ny<1) ny+=ny/(ny*N); if(ny>4) ny-=ny/(ny*N); // 1번 행은 N번 행과 연결
                if(nx<1) nx+=ny/(ny*N); if(nx>4) nx-=ny/(ny*N); // 1번 열은 N번 열과 연결
                tmpMap[ny][nx].push_back({m, s, d});
            }
        }
    }
    for(int i=1; i<=N; i++){ // 이동 상태 복사
        for(int j=1; j<=N; j++) map[i][j] = tmpMap[i][j];
    }
}

void afterMove(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(map[i][j].size()>=2){ // 2개 이상의 파이어볼이 있는 칸
                int mass=0, speed=0;
                int dir = map[i][j][0].d; // 이전 방향
                bool isAll = true;
                for(int k=0; k<map[i][j].size(); k++){
                    mass+=map[i][j][k].m;
                    speed+=map[i][j][k].s;
                    int now = map[i][j][k].d; 
                    if(dir%2!=now%2) isAll=false;
                }
                mass/=5; speed/=map[i][j].size();
                map[i][j].clear(); // 해당 칸을 비우고 
                if(isAll && mass!=0){ // 파이어볼의 방향이 모두 홀수이거나 모두 짝수 (질량이 0인 파이어볼은 소멸되어 없어짐)
                    for(int d=0; d<4; d++)
                        map[i][j].push_back({mass, speed, d*2}); // 방향은 0, 2, 4, 6
                }
                else if(mass!=0){
                    for(int d=0; d<4; d++)
                        map[i][j].push_back({mass, speed, d*2+1}); // 방향은 1, 3, 5, 7
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    int r, c, m, s, d; // 위치, 질량, 속력, 방향
    for(int i=0; i<M; i++){
        cin >> r >> c >> m >> s >> d;
        map[r][c].push_back({m, s, d});
    }
    while(K--){ // K번 이동 명령
        moveFireball(); // 파이어볼 이동
        afterMove(); // 파이어볼 이동 후
        // printMap();
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<map[i][j].size(); k++) ans+=map[i][j][k].m;
        }
    }
    cout << ans;
}