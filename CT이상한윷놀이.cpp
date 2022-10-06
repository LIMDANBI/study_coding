#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 13
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

struct MAL{
    int y, x, d;
} mals[MAX];

int N, K;
int color[MAX][MAX];
vector<int> stacked[MAX][MAX]; // 쌓인 말들

int dy[] = {0, 0, -1, 1}; // 오 왼 위 아래
int dx[] = {1, -1, 0, 0};

void input(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> color[i][j];
    }
    for(int k=1; k<=K; k++){
        int y, x, d;
        cin >> y >> x >> d;
        mals[k] = {y-1, x-1, d-1};
        stacked[y-1][x-1].push_back(k);
    }
}

bool solution(){
    for(int k=1; k<=K; k++){
        int d = mals[k].d;
        int y = mals[k].y;
        int x = mals[k].x;
        int ny = y+dy[d];
        int nx = x+dx[d];
        
        // 1. 경계를 넘거나 blue
        if(ny<0 || ny>=N || nx<0 || nx>=N || color[ny][nx]==BLUE){
            
            // 방향 전환 
            if(d==0 || d==2) mals[k].d++;
            else mals[k].d--;
            
            // 바뀐 방향 반영
            d = mals[k].d;
            ny = y+dy[d];
            nx = x+dx[d];

            // 바뀐 방향도 경계를 벗어나거나 blue인 경우 
            if(ny<0 || ny>=N || nx<0 || nx>=N || color[ny][nx]==BLUE) continue;
        }

        vector<int> &cur = stacked[y][x];
        vector<int> &next = stacked[ny][nx];
        auto start = find(cur.begin(), cur.end(), k); // k의 위치를 찾음

        // 2. red - 뒤집기
        if(color[ny][nx]==RED) reverse(start, cur.end());

        // 3. 이동
        for(auto it=start; it!=cur.end(); it++){
            mals[*it].y = ny;
            mals[*it].x = nx;
            next.push_back(*it);
        }
        cur.erase(start, cur.end());
        if(next.size()>3) return false; // 말이 4개 이상 겹쳐지는 경우가 생긴다면 그 즉시 게임을 종료
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    int round = 1;
    while(solution() && round<=1000) round++;
    if(round<=1000) cout << round;
    else cout << -1;
}