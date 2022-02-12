#include<iostream>
#include<vector>
#include<queue>
#define MAX 100
using namespace std;

struct tomato{int h, n, m;};

int M, N, H, day=0;
queue<tomato> q;
int storage[MAX][MAX][MAX];

// 인접 방향 6가지 (위, 아래, 오른쪽, 왼쪽, 앞, 뒤)
int dm[] = {0, 0, 1, -1, 0, 0};
int dn[] = {0, 0, 0, 0, -1, 1};
int dh[] = {-1, 1, 0, 0, 0, 0};

bool check(){ // 토마토가 모두 익었는지 체크
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(storage[i][j][k]==0) return false;
            }
        }
    }
    return true;
}

int bfs(){
    while (!q.empty()){
        int q_size = q.size();
        day++; // day일 째
        for(int qs=0; qs<q_size; qs++){
            int h=q.front().h;
            int n=q.front().n;
            int m=q.front().m; 
            q.pop();
            for(int i=0; i<6; i++){
                int nh = h+dh[i];
                int nn = n+dn[i];
                int nm = m+dm[i];
                if(nh<0 || nh>=H || nn<0 || nn>=N || nm<0 || nm>=M) continue; // 범위를 벗어난 경우
                if(storage[nh][nn][nm]==-1 || storage[nh][nn][nm]==1) continue; // 토마토가 없거나, 이미 익은 토마토인 경우
                storage[nh][nn][nm] = 1; // 토마토가 익음
                q.push({nh, nn, nm}); // 다음 탐색을 진행할 토마토 위치 저장
            }
        }
    }

    bool is_ripe = check(); // 토마토가 모두 익었는지 체크
    if(is_ripe) return day-1; // 모든 토마토가 익은 경우 (모든 토마토가 익은 경우에도, while문이 한 번 더 돌기 때문에 -1)
    else if(!is_ripe && q.empty()) return -1; // 토마토가 모두 익지 못하는 경우
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    bool isall = true;
    cin >> M >> N >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> storage[i][j][k];
                if(storage[i][j][k]==0) isall = false;
                if(storage[i][j][k]==1) q.push({i, j, k}); // 익은 토마토 위치 저장
            }
        }
    }
    if(isall) cout << 0; // 저장될 때부터 모든 토마토가 익어있는 상태
    else cout << bfs(); // bfs 탐색을 통해 토마토가 모두 익을 수 있는지, 몇일이 걸리는지 알아냄
}