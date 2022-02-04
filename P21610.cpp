#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

typedef pair<int, int> pi;

int N, M;
int water[MAX][MAX];
vector<pi> cloud;

// 순서대로 ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1 ,-1, 0, 1, 1, 1, 0, -1};

void move(int d, int s){

    vector<pi> moved_cloud; // 이동한 구름의 위치 좌표 저장
    bool is_cloud[MAX][MAX]={false};

    for(int i=0; i<cloud.size(); i++){ // 구름을 이동시키고 비를 내림
        int r = cloud[i].first;
        int c = cloud[i].second;
        
        // 구름 이동 (nr , nc 계산)
        int nr = ((r+dr[d-1]*s)%N+N)%N;
        int nc = ((c+dc[d-1]*s)%N+N)%N;
        
        water[nr][nc]++; // 비를 내림
        is_cloud[nr][nc]=true; // 구름이 있는지 정보 updaqte
        moved_cloud.push_back({nr, nc}); // 움직인 구름의 위치 저장
    }

    // 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양 증가
    for(int i=0; i<moved_cloud.size(); i++){
        int cnt=0;
        int r = moved_cloud[i].first;
        int c = moved_cloud[i].second;
        
        for(int k=1; k<8; k+=2){ // 대각선 확인
            int nr = r+dr[k];
            int nc = c+dc[k];
            if(0<=nr && nr<N && 0<=nc && nc<N && water[nr][nc]) cnt++; // 범위를 벗어나지 않고, 물이 있는 경우
        }
        water[r][c]+=cnt; // 물의 양 증가
    }

    vector<pi> newcloud; // 새로 생긴 구름의 좌표 저장

    for(int r=0; r<N; r++){ // 기존에 구름이 있던 칸을 제외하고 물의 양이 2 이상인 모든 칸에 구름이 생김
        for(int c=0; c<N; c++){
            if(2<=water[r][c] && !is_cloud[r][c]){
                newcloud.push_back({r,c}); // 새로 생긴 구름의 좌표 저장
                water[r][c]-=2; // 구름이 생기며 물의 양 2 감소
            }
        }
    }
    cloud = newcloud; // cloud 위치 update
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){ // water[r][c] : (r, c)에 있는 바구니에 저장되어 있는 물의 양
        for(int j=0; j<N; j++) cin >> water[i][j];
    }

    // 비바라기를 시전하면 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생김
    cloud.push_back({N-1, 0});
    cloud.push_back({N-1, 1});
    cloud.push_back({N-2, 0});
    cloud.push_back({N-2, 1});

    // M번의 이동
    int d, s, ans=0;
    for(int i=0; i<M; i++){
        cin >> d >> s;
        move(d, s); // d 방향으로 s 만큼 이동
    }

    for(int i=0; i<N; i++){ // M번의 이동이 모두 끝난 후 바구니에 들어있는 물의 양의 합을 구함
        for(int j=0; j<N; j++) ans+=water[i][j];
    }
    cout << ans;
}