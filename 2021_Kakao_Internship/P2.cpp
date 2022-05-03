#include <string>
#include <vector>
#include <cstring>
#define EMPTY 0
#define PARTITION 1
#define PERSON 2
using namespace std;

int map[5][5];
vector<int> answer;
int dy[] = {-1, 1, 0, 0}; // 상하좌우
int dx[] = {0, 0, -1, 1};
int dr[] = {-1, -1, 1, 1}; // 대각선
int dc[] = {1, -1, 1, -1};

bool check(int y, int x){ // true - 거리두기 안지킨 것 / false - 거리 두기 지킨 것
    for(int d=0; d<4; d++){
        int ny = y + dr[d];
        int nx = x + dc[d];
        if(ny<0 || ny>=5 || nx<0 || nx>=5) continue; // 범위를 벗어나는 경우
        if(map[ny][nx] == PERSON && (map[y][nx] != PARTITION || map[ny][x] != PARTITION)) return true;
    }
    for(int d=0; d<4; d++){
        for(int s=1; s<=2; s++){
            int ny = y + dy[d]*s;
            int nx = x + dx[d]*s;
            if(ny<0 || ny>=5 || nx<0 || nx>=5) continue; // 범위를 벗어나는 경우
            if(map[ny][nx] == PARTITION) break;
            if(map[ny][nx] == PERSON) return true;
        }
    }
    return false;
}

void solution(){
    for(int y=0; y<5; y++){
        for(int x=0; x<5; x++) {
            if(map[y][x] == PERSON) {
                if(check(y, x)){
                    answer.push_back(0);
                    return ;
                }
            }
        }
    }
    answer.push_back(1);
}

void input(vector<vector<string>> places){
    for(int wr=0; wr<5; wr++){ // wating room
        memset(map, 0, sizeof(map));
        for(int y=0; y<5; y++){
            for(int x=0; x<5; x++) {
                if(places[wr][y][x] == '0') map[y][x] = EMPTY;
                else if(places[wr][y][x] == 'X') map[y][x] = PARTITION;
                else if(places[wr][y][x] == 'P') map[y][x] = PERSON;
            }
        }
        solution();
    }
}

vector<int> solution(vector<vector<string>> places) {
    input(places);
    return answer;
}