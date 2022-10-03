#include<iostream>
#include<cstring>
#include<vector>
#define MAX 16
using namespace std;

int n, m;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
bool nutritional[MAX][MAX];
vector<pair<int,int>> v, tmp_v;
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

void add_tmp_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            map[i][j]+=tmp_map[i][j];
            tmp_map[i][j] = 0;
        }
    }
}

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
    // 초기 특수 영양제 위치
    v.push_back({n-1, 0});
    v.push_back({n-2, 0});
    v.push_back({n-1, 1});
    v.push_back({n-2, 1});
}

void move(){
    int dir, cnt; // 이동 방향 dir, 이동 칸 수 cnt;
    cin >> dir >> cnt; dir--;
    memset(nutritional, false, sizeof(nutritional));
    for(int i=0; i<(int)v.size(); i++){
        int y = v[i].first;
        int x = v[i].second;
        y+=dy[dir]*cnt+n; y%=n;
        x+=dx[dir]*cnt+n; x%=n;
        tmp_v.push_back({y,x});
        nutritional[y][x] = true;
    }
    v.clear();
    for(int i=0; i<(int)tmp_v.size(); i++){
        v.push_back(tmp_v[i]);
    } tmp_v.clear();
}

void insert(){
    for(int i=0; i<(int)v.size(); i++){
        int y = v[i].first;
        int x = v[i].second;
        map[y][x]++;
    }
}

void grow(){
    for(int i=0; i<(int)v.size(); i++){
        int y = v[i].first;
        int x = v[i].second;
        int cnt = 0;
        for(int d=1; d<8; d+=2){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
            if(map[ny][nx]>0) cnt++;
        }
        tmp_map[y][x] = cnt;
    }
    add_tmp_map();
}

void cut(){
    v.clear();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j]>1 && !nutritional[i][j]){ // 특수 영양제를 투입한 리브로수를 제외하고 높이가 2 이상인 리브로수
                map[i][j]-=2;
                v.push_back({i,j});
            }
        }
    }
}

void solution(){
    move(); // 특수영양제 이동
    insert(); // 특수영양제 투입
    grow(); // 리브로수 성장
    cut(); // 높이 2이상 2만큼 베어냄
}

void output(){
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) ans+=map[i][j];
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    while(m--) solution();
    output();
}