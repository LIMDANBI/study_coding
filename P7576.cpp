#include<iostream>
#include<queue>
#define MAX 1000
using namespace std;

typedef pair<int, int> pi;

int M, N, day=0;
bool isall = true;
int storage[MAX][MAX];
queue<pi> ripe_tomato;

// 인접 방향 4가지 (오른쪽, 왼쪽, 앞, 뒤)
int dn[] = {0, 0, 1, -1};
int dm[] = {1, -1, 0, 0};

int bfs(){
    while (!ripe_tomato.empty()){
        day++;
        int ripe_size = ripe_tomato.size();
        for(int r=0; r<ripe_size; r++){
            int n = ripe_tomato.front().first;
            int m = ripe_tomato.front().second;
            ripe_tomato.pop();
            for(int i=0; i<4; i++){
                int nn = n+dn[i];
                int nm = m+dm[i];
                if(nn<0 || nn>=N || nm<0 || nm>=M) continue; // 범위를 벗어나는 경우
                if(storage[nn][nm]==-1 || storage[nn][nm]==1) continue; // 토마토가 없거나, 이미 익은 경우
                storage[nn][nm] = 1; // 앞의 경우가 아닌 경우, 토마토를 익히고
                ripe_tomato.push({nn, nm}); // 다음 탐색을 위해 큐에 넣어줌
            }
        }
    }

    // 토마토가 다 익었는지 체크
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(storage[i][j]==0) return -1; // 토마토가 모두 익지 못하는 경우
        }
    }
    return day-1; // 토마토가 다 익을 수 있는 경우
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> storage[i][j];
            if(storage[i][j]==0) isall = false;
            if(storage[i][j]==1) ripe_tomato.push({i, j}); // 익은 토마토 위치 저장
        }
    }
    if(isall) cout << 0; // 저장될 때부터 모든 토마토가 익어있는 상태
    else cout << bfs(); // bfs 탐색을 통해 토마토가 모두 익을 수 있는지, 몇일이 걸리는지 알아냄
}