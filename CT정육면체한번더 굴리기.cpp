#include<iostream>
#include<cstring>
#include<queue>
#define MAX 21
using namespace std;

int dice_y=0, dice_x=0, dir=3; // 주사위 위치, 방향 
int dice[6] = {1, 6, 2, 5, 3, 4};  // 상 하 앞 뒤 우 좌

int n, m, ans=0;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = {1, 0, -1, 0};  // 하, 좌, 상, 우
int dx[] = {0, -1, 0, 1};

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
}

int get_score(int i, int j, int num){
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({i, j});
    int size = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
            if(visited[ny][nx] || map[ny][nx]!=num) continue;
            visited[ny][nx] = true;
            q.push({ny,nx});
            size++;
        }
    }
    return size*num;
}

void roll_the_dice(){
    int tmp = dice[0];
    if(dir==0){ // 하
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = tmp;
    }
    else if(dir==1){ // 좌
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = tmp;
    }
    else if(dir==2){ // 상
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = tmp;
    }
    else{ // 우 
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = tmp;
    }
}

void select_new_dir(){
    int bottom = dice[1];
    if(map[dice_y][dice_x] < bottom){ // 90' 시계방향
        dir++; dir%=4;
    }
    else if(map[dice_y][dice_x] > bottom){ // 90' 반시계방향
        dir--; if(dir<0) dir+=4;
    }
}

void solution(){
    while(m--){
        dice_y+=dy[dir];  // 주사위 이동 
        dice_x+=dx[dir];
        if(dice_y<0 || dice_y>=n || dice_x<0 || dice_x>=n){ // 범위를 벗어나는 경우
            dir+=2; dir%=4; // 방향 반대로
            dice_y+=dy[dir]*2; // 반대 방향으로 이동
            dice_x+=dx[dir]*2;
        }
        ans += get_score(dice_y, dice_x, map[dice_y][dice_x]); // 점수 얻음 
        roll_the_dice(); // 주사위 굴린 상태로 변경
        select_new_dir(); // 새로운 방향 설정
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << ans;
}