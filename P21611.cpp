#include<iostream>
#include<vector>
#include<queue>
#define MAX 50
#define EMPTY 0
using namespace std;

struct POS{int y, x;};
POS Shark;

int N, M, ans=0;
int map[MAX][MAX];
vector<POS> order;
int dy[] = {0, 1, 0, -1}; // 좌 하 우 상
int dx[] = {-1, 0, 1, 0};
int dr[] = {-1, 1, 0, 0}; // ↑, ↓, ←, →
int dc[] = {0, 0, -1, 1};

void destroyMarble(int d, int S){ // 얼음 파편 공격
    for(int move=1; move<=S; move++){
        int ny = Shark.y + dr[d]*move;
        int nx = Shark.x + dc[d]*move;
        map[ny][nx] = EMPTY; // 구슬 파괴
    }
}

void moveMarble(){ // 구슬 이동
    queue<int> q;
    int y, x, cnt=0;
    y = x = Shark.y;
    while (x!=0){
        for(int dir=0; dir<4; dir++){
            if(dir%2==0) cnt++;
            for(int move=0; move<cnt; move++){
                y+=dy[dir];
                x+=dx[dir];
                if(x==0) break;
                if(map[y][x]!=EMPTY) q.push(map[y][x]);
            }
            if(x==0) break;
        }
    }
    y = x = Shark.y; cnt=0;
    while (x!=0){
        for(int dir=0; dir<4; dir++){
            if(dir%2==0) cnt++;
            for(int move=0; move<cnt; move++){
                y+=dy[dir];
                x+=dx[dir];
                if(x==0) break;
                if(q.empty()) map[y][x] = EMPTY;
                else{
                    map[y][x] = q.front();
                    q.pop();
                }
            }
            if(x==0) break;
        }
    }
}

void explodeMarble(){ // 4개 이상 연속하는 구슬 폭발, ans = 1×(폭발한 1번 구슬의 개수) + 2×(폭발한 2번 구슬의 개수) + 3×(폭발한 3번 구슬의 개수)
    queue<int> q;
    bool flag=false; // 4개 이상 연속 구슬이 있는지
    int before=0, num=0;
    int y, x, cnt=0;
    y = x = Shark.y;
    while (x!=0){
        for(int dir=0; dir<4; dir++){
            if(dir%2==0) cnt++;
            for(int move=0; move<cnt; move++){
                y+=dy[dir];
                x+=dx[dir];
                if(x==0) break;
                if(before==map[y][x]) num++;
                else{
                    if(num>3) {
                        ans+=before*num;
                        flag = true;
                    }
                    else if(before!=0){
                        while(num--) q.push(before);
                    } 
                    num = 1;
                    before = map[y][x];
                }
            }
            if(x==0) break;
        }
    }
    if(!flag) return;
    y = x = Shark.y; cnt=0;
    while (x!=0){
        for(int dir=0; dir<4; dir++){
            if(dir%2==0) cnt++;
            for(int move=0; move<cnt; move++){
                y+=dy[dir];
                x+=dx[dir];
                if(x==0) break;
                if(q.empty()) map[y][x] = 0;
                else{
                    map[y][x] = q.front();
                    q.pop();
                }
            }
            if(x==0) break;
        }
    }
    explodeMarble();
}

void changeMarble(){ // 구슬 변화 (A - 그룹에 들어있는 구슬 개수, B - 그룹을 이루고 있는 구슬 번호)
    queue<int> q;
    int before=0, num=0;
    int y, x, cnt=0;
    y = x = Shark.y;
    while (x!=0){
        for(int dir=0; dir<4; dir++){
            if(dir%2==0) cnt++;
            for(int move=0; move<cnt; move++){
                y+=dy[dir];
                x+=dx[dir];
                if(x==0) break;
                if(before==map[y][x]) num++;
                else{
                    if(before!=0){
                        q.push(num);
                        q.push(before);
                    }
                    num = 1;
                    before = map[y][x];
                }
            }
            if(x==0) break;
        }
    }
    y = x = Shark.y; cnt=0;
    while (x!=0){
        for(int dir=0; dir<4; dir++){
            if(dir%2==0) cnt++;
            for(int move=0; move<cnt; move++){
                y+=dy[dir];
                x+=dx[dir];
                if(x==0) break;
                if(q.empty()) map[y][x] = 0;
                else{
                    map[y][x] = q.front();
                    q.pop();
                }
            }
            if(x==0) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    Shark.y = Shark.x = (N+1)/2;
    for(int i=1; i<=N; i++){ // 입력 
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    while (M--){ // 블리자드 M번 시전
        int d, s;
        cin >> d >> s;
        destroyMarble(d-1, s);
        moveMarble();
        explodeMarble();
        changeMarble();
    }
    cout << ans;
}