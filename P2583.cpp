#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int N, M, K, ans=0;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool rectangle[MAX][MAX], visited[MAX][MAX];
priority_queue<int> pq;

void cololring(int lx, int ly, int rx, int ry){
    for(int i=ly; i<ry; i++){
        for(int j=lx; j<rx; j++) rectangle[i][j] = true;
    }
}

int bfs(int i, int j){
    int res = -1;
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({i, j});
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue; // 범위를 벗어나는 경우
            if(rectangle[ny][nx] || visited[ny][nx]) continue; // 직사각형 내부인 경우, 이미 방문한 경우
            visited[ny][nx] = true;
            q.push({ny, nx});
            res--;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    int lx, ly, rx, ry; // 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값
    while (K--){ // 직사각형 내부 체크 
        cin >> lx >> ly >> rx >> ry;
        cololring(lx, ly, rx, ry);
    }
    for(int i=0; i<N; i++){ // 분리된 각 영역의 넓이를 구함
        for(int j=0; j<M; j++){
            if(visited[i][j] || rectangle[i][j]) continue;
            int area = bfs(i, j); 
            pq.push(area);
        }
    }
    cout << pq.size() << "\n"; // 분리되어 나누어지는 영역의 개수
    while (!pq.empty()) { // 각 영역의 넓이를 오름차순으로 정렬해서 출력
        cout << -pq.top() << " ";
        pq.pop();
    }
}