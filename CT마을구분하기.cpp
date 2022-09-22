#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 26
using namespace std;

int n, cnt;
vector<int> v;
int map[MAX][MAX];
bool visited[MAX][MAX];

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
}

void dfs(int y, int x){
    if(y<0 || y>=n || x<0 || x>=n) return ;
    if(map[y][x]==0 || visited[y][x]) return ;
    visited[y][x] = true;
    cnt++;
    dfs(y+1, x);
    dfs(y-1, x);
    dfs(y, x+1);
    dfs(y, x-1);
}

void solution(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cnt = 0;
            dfs(i, j);
            if(cnt!=0) v.push_back(cnt);
        }
    }
}

void output(){
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++) cout << v[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}
