#include<iostream>
#define MAX 20
using namespace std;

int N, M, K;
int diceY, diceX;

int dice[7]={0}; // 상(1), 옆1(2), 옆2(3), 옆3(4), 옆4(5), 하(6)
int map[MAX][MAX];
int dy[] = {0, 0, -1, 1}; // 동, 서, 북, 남
int dx[] = {1, -1, 0, 0};

void changeDice(int dir){
    int tmp = dice[1];
    if(dir==0){ // 동
        dice[1]=dice[4];
        dice[4]=dice[6];
        dice[6]=dice[3];
        dice[3]=tmp;
    }
    else if(dir==1){ // 서
        dice[1]=dice[3];
        dice[3]=dice[6];
        dice[6]=dice[4];
        dice[4]=tmp;
    }
    else if(dir==2){ // 북
        dice[1]=dice[5];
        dice[5]=dice[6];
        dice[6]=dice[2];
        dice[2]=tmp;
    }
    else if(dir==3){ // 남
        dice[1]=dice[2];
        dice[2]=dice[6];
        dice[6]=dice[5];
        dice[5]=tmp;
    }
}

void Move(int dir){
    int ny = diceY+dy[dir];
    int nx = diceX+dx[dir];
    if(ny<0 || ny>=N || nx<0 || nx>=M) return; // 범위를 벗어나는 경우 (출력 x)
    changeDice(dir);
    if(map[ny][nx]==0) // dice to map
        map[ny][nx] = dice[6];
    else{ // map to dice
        dice[6] = map[ny][nx];
        map[ny][nx] = 0;
    }
    diceY = ny; diceX = nx;
    cout << dice[1] << "\n";
}

void Input(){
    cin >> N >> M >> diceY >> diceX >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> map[i][j];
    }
    for(int i=0; i<K; i++){
        int dir; cin >> dir; // 이동 명령
        Move(dir-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    Input();
}