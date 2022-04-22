#include <iostream>
#include<vector>
#include <queue>
#define MAX_N 50
using namespace std;

int sy, sx;
int N, M, d, s, ans=0;
int grid[MAX_N][MAX_N];
int dy[]={0, -1, 1, 0, 0}; //  ↑, ↓, ←, → (1, 2, 3, 4)
int dx[]={0, 0, 0, -1, 1};
int dr[] = {0, 1, 0, -1}; // 반시계 방향 (좌 하 우 상)
int dc[] = {-1, 0, 1, 0};
vector<pair<int, int>> v;

void destroy_bead(int D, int S){ // 구슬 파괴
    for(s=1; s<=S; s++){
        int ny = sy + dy[D]*s;
        int nx = sx + dx[D]*s;
        if(ny<1 || ny>N || nx<1 || nx>N || grid[ny][nx]==0) continue; // 범위를 벗어나거나 구슬이 없는 경우
        grid[ny][nx] = 0; // 구슬 파괴
    }
}

void move_bead(){ // 구슬 이동
    queue<int> q;
    int r=sy, c=sx, cnt=0;
    while (1){
        for(int i=0; i<4; i++){
            if(i%2==0) cnt++;
            for(int j=0; j<cnt; j++){
                r+=dr[i];
                c+=dc[i];
                if(grid[r][c]!=0) q.push(grid[r][c]);
                if(c==0) break;
            }
            if(c==0) break;
        }
        if(c==0) break;
    }
    r=sy; c=sx; cnt=0;
    while (1){
        for(int i=0; i<4; i++){
            if(i%2==0) cnt++;
            for(int j=0; j<cnt; j++){
                r+=dr[i];
                c+=dc[i];
                if(!q.empty()){
                    grid[r][c] = q.front();
                    q.pop();
                }
                else grid[r][c] = 0;
                if(c==0) return;
            }
        }
    }
}

void explosion_bead(){ // 구슬 폭발이 일어남
    while (1){
        bool is_continue = false;
        vector<pair<int, int>> pos;
        int r=sy, c=sx, cnt=0;
        int before=grid[r][c];
        while (1){ // 구슬 폭발
            for(int i=0; i<4; i++){
                if(i%2==0) cnt++;
                for(int j=0; j<cnt; j++){
                    r+=dr[i];
                    c+=dc[i];
                    if(grid[r][c]==before && grid[r][c]!=0) pos.push_back({r,c});
                    else{
                        if(pos.size()>3){
                            is_continue = true;
                            ans+=before*pos.size();
                            for(int k=0; k<pos.size(); k++) grid[pos[k].first][pos[k].second] = 0; // 폭파
                        }
                        pos.clear();
                        pos.push_back({r,c});
                        before = grid[r][c];
                    }
                    if(c==0) {
                        if(pos.size()>3){
                            is_continue = true;
                            ans+=before*pos.size();
                            for(int k=0; k<pos.size(); k++) grid[pos[k].first][pos[k].second] = 0; // 폭파
                        }
                        break;
                    }
                }
                if(c==0) break;
            }
            if(c==0) break;
        }
        if(!is_continue) return;
        move_bead(); // 구슬 이동
    }
}

void change_bead(){ // 구슬 변화
    queue<int> q;
    int r=sy, c=sx, cnt=0;
    int A=0, B=grid[r][c];
    while (1){
        for(int i=0; i<4; i++){
            if(i%2==0) cnt++;
            for(int j=0; j<cnt; j++){
                r+=dr[i];
                c+=dc[i];
                if(grid[r][c]==B) A++;
                else{
                    if(B!=0){
                        q.push(A); // 그룹에 들어있는 구슬 수 (A)
                        q.push(B); // 그룹을 이루고 있는 구슬 번호 (B)
                    }
                    B = grid[r][c];
                    A = 1;
                }
                if(c==0) {
                    if(B!=0){
                        q.push(A); // 그룹에 들어있는 구슬 수 (A)
                        q.push(B); // 그룹을 이루고 있는 구슬 번호 (B
                    }
                    break;
                }
            }
            if(c==0) break;
        }
        if(c==0) break;
    }
    r=sy; c=sx; cnt=0;
    while (1){
        for(int i=0; i<4; i++){
            if(i%2==0) cnt++;
            for(int j=0; j<cnt; j++){
                r+=dr[i];
                c+=dc[i];
                if(!q.empty()){
                    grid[r][c] = q.front();
                    q.pop();
                }
                else grid[r][c] = 0;
                if(c==0) return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cin >> grid[i][j];
    }
    for(int i=0; i<M; i++){
        cin >> d >> s;
        v.push_back({d, s});
    }
    sy = (N+1)/2; sx = (N+1)/2; // 상어 위치
    for(int i=0; i<M; i++){ // blizzard
        d = v[i].first, s = v[i].second;
        destroy_bead(d, s); // 구슬 파괴
        move_bead(); // 구슬 이동
        explosion_bead(); // 구슬 폭발 + 이동 (폭발이 더 이상 일어나지 않을 때 까지)
        change_bead(); // 구슬 변화
    }
    cout << ans;
}