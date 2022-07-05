#include<iostream>
#include<queue>
#define MAX 251
#define FIELD 0
#define FENCE 1
#define SHEEP 2
#define WOLF 3
using namespace std;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int map[MAX][MAX];
bool visit[MAX][MAX];
int sheep=0, wolf=0, R, C;

void bfs(int i, int j){
    queue<pair<int, int>> q;
    int w=0, s=0; // 같은 영역 안 늑대 수 , 양 수
    q.push({i,j});
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        visit[y][x] = true;
        if(map[y][x] == WOLF) w++;
        else if(map[y][x] == SHEEP) s++;
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(visit[ny][nx] || map[ny][nx]==FENCE || ny<0 || ny>=R || nx<0 || nx>=C) continue; // 이미 방문한 경우, 울타리인 경우, 격자에서 벗어나는 경우
            q.push({ny, nx});
        }
    }
    if(w!=0 && s!=0){
        if(w<s) wolf-=w;
        else sheep-=s;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    string str;
    for(int i=0; i<R; i++){
        cin >> str;
        for(int j=0; j<C; j++){
            if(str[j]=='.') map[i][j] = FIELD;
            else if(str[j]=='#') map[i][j] = FENCE;
            else if(str[j]=='o') {
                map[i][j] = SHEEP;
                sheep++;
            }
            else if(str[j]=='v') {
                map[i][j] = WOLF;
                wolf++;
            }
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(visit[i][j] || map[i][j]==FENCE) continue;
            bfs(i, j);
        }
    }
    cout << sheep << " " << wolf;
}