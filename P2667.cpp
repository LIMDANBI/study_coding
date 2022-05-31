#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 25
using namespace std;

int N, res;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

vector<int> ans;

int dfs(int y, int x){ // dfs 탐색을 통해 단지 내 집의 수를 구함
    visit[y][x] = true;
    for(int d=0; d<4; d++){
        int ny = y+dy[d];
        int nx = x+dx[d];
        if(ny<0 || ny>=N || nx<0 || nx>=N) continue; // 범위를 벗어나는 경우
        if(visit[ny][nx] || !map[ny][nx]) continue; // 이미 방문했거나, 집이 없는 경우
        res++;
        dfs(ny, nx);
    }
    return res; // 단지 내 집의 수
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<N; j++) map[i][j] = str[j]-'0';
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visit[i][j] || !map[i][j]) continue;  // 이미 방문했거나, 집이 없는 경우
            res=1;
            dfs(i,j);
            ans.push_back(res);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n"; // 단지수
    for(int i=0; i<ans.size(); i++) cout << ans[i] << "\n"; // 단지 내 집의 수
}