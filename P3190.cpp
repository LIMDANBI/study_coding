#include<iostream>
#include<queue>
#define MAX 101
#define EMPTY -1
using namespace std;

int N, K, L;
int snake[MAX][MAX];
bool apple[MAX][MAX];
int sy=0, sx=0, ey=0, ex=0, dir=1; // 뱀의 정보 

int dy[] = {-1, 0, 1, 0}; // 상 우 하 좌 
int dx[] = {0, 1, 0, -1};

queue<pair<int, int>> info; // 방향 변환 정보 

void input(){
    cin >> N >> K;
    int r, c, t; char d;
    for(int i=0; i<K; i++){
        cin >> r >> c;
        apple[r-1][c-1] = true;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        cin >> t >> d;
        if(d=='L') info.push({t, 0}); // 'L' 외쪽으로 90'
        else info.push({t, 1}); // 'D' 오른쪽으로 90'
    }

    // init
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) snake[i][j] = EMPTY;
    }
}

void solution(){
    int ans=0;
    snake[0][0] = 1;
    while(1){
        
        ans++;
        
        // 1. 뱀 이동
        sy+=dy[dir];
        sx+=dx[dir];
        if(sy<0 || sy>=N || sx<0 || sx>=N || snake[sy][sx]!=EMPTY) break; // 벽 또는 자기자신의 몸과 부딪히는 경우
        if(apple[sy][sx]) apple[sy][sx] = 0; // 사과가 있는 경우, 사과를 먹음
        else{ // 사과가 없는 경우, 몸길이를 줄임
            int d = snake[ey][ex];
            snake[ey][ex] = -1;
            ey+=dy[d];
            ex+=dx[d];
        }

        // 2. 방향 변화
        if(!info.empty() && info.front().first == ans){
            if(info.front().second) dir = (dir+1)%4; // 오른쪽으로 90'
            else dir = (dir+4-1)%4; // 외쪽으로 90'
            info.pop();
        }
        snake[sy][sx] = dir; // 방향 저장
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}