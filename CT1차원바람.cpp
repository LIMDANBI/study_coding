#include<iostream>
#define MAX 101
#define LEFT 0
#define RIGHT 1
using namespace std;

int N, M, Q, tmp;
int map[MAX][MAX];

void input(){
    cin >> N >> M >> Q;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) 
            cin >> map[i][j];
    }
}

void wind(int row, int dir){ // 바람의 방향에 따라 row 행 원소들 이동
    if(dir==RIGHT){
        tmp = map[row][1];
        for(int i=1; i<M; i++) map[row][i] = map[row][i+1];
        map[row][M] = tmp;
    }
    else{
        tmp = map[row][M];
        for(int i=M; i>1; i--) map[row][i] = map[row][i-1];
        map[row][1] = tmp;        
    }
}

void move(){
    while(Q--){

        int row, dir; char d;
        cin >> row >> d;
        d=='L' ? dir=LEFT : dir=RIGHT;
        wind(row, dir);

        int up = row-1, up_dir=dir; // UP
        while(up>0){
            bool isterminate = true;
            for(int i=1; i<=M; i++){
                if(map[up+1][i]==map[up][i]){ // 하나의 열의 원소라도 일치하는 경우 
                    up_dir = !up_dir; // 방향 change
                    wind(up, up_dir); // 바람이 불어 행 이동
                    up--;
                    isterminate = false;
                    break;
                }
            }
            if(isterminate) break;
        }

        int down=row+1, down_dir=dir; // DOWN
        while(down<=N){
            bool isterminate = true;
            for(int i=1; i<=M; i++){
                if(map[down-1][i]==map[down][i]){ // 하나의 열의 원소라도 일치하는 경우 
                    down_dir = !down_dir; // 방향 change
                    wind(down, down_dir); // 바람이 불어 행 이동
                    down++;
                    isterminate = false;
                    break;
                }
            }
            if(isterminate) break;
        }
    }
}

void output(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) 
            cout << map[i][j] << " ";
        cout << "\n";
    } 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    move();
    output();
}