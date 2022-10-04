#include<iostream>
#include<cstring>
#include<queue>
#define MAX 26
#define EMPTY 0
using namespace std;

int n, m, ans=0;
int map[MAX][MAX];

int ay[] = {0, 1, 0, -1};
int ax[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
}

void print_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << map[i][j] << " ";
        cout << "\n";
    }
}

void attack_monster(){
    int dir, cnt; // 공격 방향, 공격 칸 수
    cin >> dir >> cnt;
    int y=n/2, x=n/2;
    for(int i=0; i<cnt; i++){
        y+=ay[dir]; x+=ax[dir];
        ans+=map[y][x];
        map[y][x] = EMPTY;
    }
}

void fill_blank(){

    queue<int> q;

    // EMPTY 제외 queue에 넣기 
    int y=n/2, x=n/2, cnt=0;
    for(int d=0; x>=0; d++){ d%=4;
        if(d%2==0) cnt++;
        for(int c=0; c<cnt; c++){
            y+=dy[d];
            x+=dx[d];
            // cout << y << " " << x << "\n";
            if(x<0) break;
            if(map[y][x]!=EMPTY) q.push(map[y][x]);
        }
        if(x<0) break;
    }

    // queue to map
    memset(map, 0, sizeof(map));
    y=n/2; x=n/2; cnt = 0;
    for(int d=0; x>=0 && !q.empty(); d++){ d%=4;
        if(d%2==0) cnt++;
        for(int c=0; c<cnt; c++){
            y+=dy[d];
            x+=dx[d];
            if(x<0 || q.empty()) break;
            map[y][x] = q.front();
            q.pop();
        }
        if(x<0 || q.empty()) break;
    }
}

void remove_repetition(){
    bool flag = true;
    while(flag){
        
        queue<int> q;
        
        int y=n/2, x=n/2, cnt=0;
        int monster=map[y][x-1], num=0;
        for(int d=0; x>=0; d++){ d%=4;
            if(d%2==0) cnt++;
            for(int c=0; c<cnt; c++){
                y+=dy[d];
                x+=dx[d];
                if(x<0) break;
                if(monster!=map[y][x]){
                    if(num<4){
                        while(num--) q.push(monster);
                    }
                    else {
                        ans += monster*num;
                        flag = false;
                    }
                    monster = map[y][x];
                    num = 1;
                }
                else num++;
            }
            if(x<0) break;
        }

        flag = !flag;

        // queue to map
        memset(map, 0, sizeof(map));
        y=n/2; x=n/2; cnt = 0;
        for(int d=0; x>=0 && !q.empty(); d++){ d%=4;
            if(d%2==0) cnt++;
            for(int c=0; c<cnt; c++){
                y+=dy[d];
                x+=dx[d];
                if(x<0 || q.empty()) break;
                map[y][x] = q.front();
                q.pop();
            }
            if(x<0 || q.empty()) break;
        }
    }
}

void list_up_monster(){

    queue<int> q;

    int y=n/2, x=n/2, cnt=0;
    int monster=map[y][x-1], num=0;
    for(int d=0; x>=0; d++){ d%=4;
        if(d%2==0) cnt++;
        for(int c=0; c<cnt; c++){
            y+=dy[d];
            x+=dx[d];
            if(x<0) break;
            if(monster!=map[y][x]){
                q.push(num); num = 1;
                q.push(monster); monster = map[y][x];
            }
            else num++;
        }
        if(x<0) break;
    }

    // queue to amp
    memset(map, 0, sizeof(map));
    y=n/2; x=n/2; cnt = 0;
    for(int d=0; x>=0 && !q.empty(); d++){ d%=4;
        if(d%2==0) cnt++;
        for(int c=0; c<cnt; c++){
            y+=dy[d];
            x+=dx[d];
            if(x<0 || q.empty()) break;
            map[y][x] = q.front();
            q.pop();
        }
        if(x<0 || q.empty()) break;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    while(m--){
        attack_monster();
        fill_blank();
        remove_repetition();
        list_up_monster();
    }
    cout << ans;
}