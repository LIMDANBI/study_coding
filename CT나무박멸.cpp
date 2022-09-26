#include<iostream>
#include<cstring>
#define MAX 20
#define EMPTY 0
#define WALL -1
using namespace std;

int n, m, k, c, ans=0;
int hy, hx;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
int herbicide[MAX][MAX];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void printmap(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << herbicide[i][j] << " ";
        cout << "\n";
    }
}

void input(){
    cin >> n >> m >> k >> c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
}

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) map[i][j] = tmp_map[i][j];
    }
    memset(tmp_map, 0, sizeof(tmp_map));
}

void grow_tree(){ // 나무의 성장
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j]<1) {
                tmp_map[i][j] = map[i][j];
                continue;
            }
            int cnt = 0;
            for(int d=0; d<8; d+=2){
                int ny = i+dy[d];
                int nx = j+dx[d];
                if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if(map[ny][nx]>0) cnt++;
            }
            tmp_map[i][j] = map[i][j] + cnt;
        }
    }
    copy();
}

void breeding_tree(){ // 나무의 번식
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp_map[i][j] += map[i][j];
            if(herbicide[i][j] || map[i][j]==-1) continue; // 나무가 아닌 칸
            int cnt = 0; // 번식 가능한 칸 
            for(int d=0; d<8; d+=2){
                int ny = i+dy[d];
                int nx = j+dx[d];
                if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if(map[ny][nx]==EMPTY && !herbicide[ny][nx]) cnt++;
            }
            if(cnt == 0) continue;
            int tree = map[i][j]/cnt;
            for(int d=0; d<8; d+=2){
                int ny = i+dy[d];
                int nx = j+dx[d];
                if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if(map[ny][nx] == EMPTY && !herbicide[ny][nx]) tmp_map[ny][nx] += tree;
            }
        }
    }
    copy();
}

void select_herbicide(){ // 제초제를 뿌릴 위치 선정
    int max_extermination = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(herbicide[i][j] || map[i][j]<1) continue;
            int extermination = map[i][j];
            for(int d=1; d<8; d+=2){
                for(int b=1; b<=k; b++){
                    int ny = i+dy[d]*b;
                    int nx = j+dx[d]*b;
                    if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                    if(map[ny][nx]<1) break;
                    extermination+=map[ny][nx];
                }
            }
            if(max_extermination < extermination){
                hy = i; hx = j;
                max_extermination = extermination;
            }
        }
    }
    ans += max_extermination;
    // cout << hy << " " << hx << "\n";
    // cout << max_extermination << "\n";
}

void spred_herbicide(){ // 제초제를 뿌리는 작업 진행
    map[hy][hx] = EMPTY;
    herbicide[hy][hx] = c+1;
    for(int d=1; d<8; d+=2){
        for(int b=1; b<=k; b++){
            int ny = hy+dy[d]*b;
            int nx = hx+dx[d]*b;
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
            if(map[ny][nx]<1) {
                if(map[ny][nx]==EMPTY) herbicide[ny][nx] = c+1;
                break;
            }
            map[ny][nx] = EMPTY;
            herbicide[ny][nx] = c+1;
        }
    }
}

void remove_herbicide(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(herbicide[i][j]) herbicide[i][j]--;
        }
    }
}

void solution(){
    while(m--){
        grow_tree(); // 나무의 성장
        breeding_tree(); // 나무의 번식
        select_herbicide(); // 제초제를 뿌릴 위치 선정
        spred_herbicide(); // 제초제를 뿌리는 작업 진행
        // printmap();
        // cout << "\n";
        remove_herbicide(); // 제초체 감소
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << ans;
}