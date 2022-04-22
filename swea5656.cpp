#include<iostream>
#include<cstring>
#include<queue>
#define MAX_W 13
#define MAX_H 16
#define MAX 987654321
using namespace std;

int ans;
int N, W, H; // 쏠 기회, W x H 배열
int brick[MAX_H][MAX_W]; // 벽돌 정보
bool visit[MAX_H][MAX_W]; // 방문 여부

int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};

void drop(){ // 벽돌이 밑으로 떨어짐
    for(int w=1; w<=W; w++){
        queue<int> q; 
        for(int h=H; h>0; h--){
            if(brick[h][w]){
                q.push(brick[h][w]);
                brick[h][w] = 0;
            }
        }
        int idx = H;
        while (!q.empty()){
            brick[idx][w] = q.front();
            q.pop();
            idx--;
        }
    }
}

void breaking(int i, int j){ // 벽돌을 깸
    memset(visit, 0, sizeof(visit)); // 방문 여부 초기화 
    queue<pair<int, int>> q;
    visit[i][j] = true;
    q.push({i,j});

    while (!q.empty()){
        int h = q.front().first;
        int w = q.front().second;
        q.pop();
        int cnt = brick[h][w];
        brick[h][w] = 0; // 벽돌 깨기

        if(cnt>1){
            for(int i=0; i<4; i++) {
				for(int z=1; z<cnt; z++){
					int nh = h + dh[i] * z;
                    int nw = w + dw[i] * z;
                    if(nh<1 || nh>H || nw<1 || nw>W || visit[nh][nw] || !brick[nh][nw]) continue;
                    visit[nh][nw] = true;
                    q.push({nh, nw});
                }
            }
        }
    }
}

void solve(int cnt){
    if(cnt==N){ // 구슬을 N번 다 쏜 경우
        int res = 0;
        for(int h=1; h<=H; h++){
            for(int w=1; w<=W; w++){
                if(brick[h][w]>0) res++; // 남은 벽돌의 개수
            }
        }
        ans = min(ans, res);
        return ;
    }
    int copy_brick[MAX_H][MAX_W];
    for(int h=1; h<=H; h++){
        for(int w=1; w<=W; w++) copy_brick[h][w] = brick[h][w]; // 배열 복사
    }
    // 구슬 쏘기
    for(int w=1; w<=W; w++){ // 가장 위에 있는 벽돌만 깰 수 o
        for(int h=1; h<=H; h++){
            if(brick[h][w]){ // 벽돌이 있는 경우
                breaking(h, w); // 벽돌을 깸
                drop(); // 벽돌이 밑으로 떨어짐
                solve(cnt+1);
                for(int h=1; h<=H; h++){
                    for(int w=1; w<=W; w++) brick[h][w] = copy_brick[h][w]; // 배열 복구
                }
                break; // 가장 위에 있는 벽돌만 깰 수 o
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        ans = MAX;
        cin >> N >> W >> H;
        for(int h=1; h<=H; h++){ // 벽돌 정보 입력 받음
            for(int w=1; w<=W; w++) cin >> brick[h][w];
        }
        solve(0);
        if(ans==MAX) ans=0;
        cout << "#" << t << " " << ans << "\n"; // 남은 벽돌의 개수
    }
}