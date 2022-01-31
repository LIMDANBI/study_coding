#include<iostream>
#include<cstring>
#include<queue>
#define MAX_N 21
using namespace std;

struct shark{
    int d, y, x; // 거리, y좌표, x좌표
    bool operator < (const shark &t) const{ // (연산자 오버로딩, 비교 순서) 거리 > 상 > 좌
        if(d == t.d){ // 거리가 같다면
            if(y == t.y) return x > t.x; // y(상하)좌표도 같다면, 왼쪽에 있는 것 우선! 
            else return y > t.y; // y좌표가 다르다면 위에 있는 것 우선!
        }
        else return d > t.d; // 거리가 다른 경우 거리 우선
    }
};

int N, shark_size=2, eat=0, ans=0;
int space[MAX_N][MAX_N];
bool check[MAX_N][MAX_N];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1}; // 상 하 좌 우
priority_queue<shark> pq;

void bfs(){
    while (!pq.empty()){
        int d = pq.top().d;
        int y = pq.top().y;
        int x = pq.top().x;
        pq.pop();

        if(0 < space[y][x] && space[y][x]<shark_size){ // 물고기를 잡아 먹을 수 있는 경우
            space[y][x] = 0; // 잡아 먹고
            eat++; // 잡아 먹은 수를 증가
            if(eat == shark_size){ // 자신의 크기 만큼 잡아 먹었다면
                shark_size++; // 크기 증가
                eat = 0; // 크기 업데이트 후 먹은 물고기가 아직 없으므로, 다시 0으로 설정!
            }
            ans+=d; // 물고기를 먹기위해 이동한 거리를 더해줌
            d=0; // 거리 초기화! (다시 이 지점(y, x)부터 탐색 시작)
            memset(check, false, sizeof(check)); // 방문 여부 배열 초기화
            while (!pq.empty()) pq.pop(); // pq를 비워줌
        }

        for(int i=0; i<4; i++){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny<1 || ny>N || nx<1 || nx>N) continue; // space를 벗어나는 경우
            if(check[ny][nx]) continue; // 이미 방문한 경우 
            if(0<space[ny][nx] && shark_size<space[ny][nx]) continue; // 상어보다 큰 물고기인 경우
            pq.push({d+1, ny, nx}); // 앞에 경우들이 아닌 경우 pq에 넣고,
            check[ny][nx] = true;  // 방문 여부를 true로 update
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) {
            cin >> space[i][j];
            if(space[i][j] == 9){ 
                pq.push({0, i, j}); // 시작 좌표 저장
                space[i][j] = 0; 
            }
        }
    }
    bfs(); // bfs 탐색을 진행하며 답을 구함
    cout << ans;
}