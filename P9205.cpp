#include<iostream>
#include<cstring>
#include<vector>
#define MAX 101
#define MAX_DIST 1000
using namespace std;

int t, n, px, py;
bool ishappy, visited[MAX];
int home_x, home_y; // 상근이네 집 좌표
vector<pair<int, int>> pos; // 편의점 좌표
int fes_x, fes_y; // 펜타포트 락 페스티벌 좌표

void init(){ // 초기화
    pos.clear();
    ishappy = false;
    memset(visited, false, sizeof(visited));
}

void input(){
    cin >> n;
    cin >> home_x >> home_y;
    for(int i=0; i<n; i++){
        cin >> px >> py;
        pos.push_back({px, py});
    }
    cin >> fes_x >> fes_y;
}

void dfs(int nx, int ny, int dx, int dy){
    if(ishappy) return;
    if(abs(nx-dx)+abs(ny-dy) <= MAX_DIST) {
        ishappy = true;
        return;
    }
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        if(MAX_DIST < abs(pos[i].first-nx)+abs(pos[i].second-ny)) continue;
        visited[i] = true;
        dfs(pos[i].first, pos[i].second, dx, dy);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        init();
        input();
        dfs(home_x, home_y, fes_x, fes_y);
        if(ishappy) cout << "happy\n";
        else cout << "sad\n";
    }
}