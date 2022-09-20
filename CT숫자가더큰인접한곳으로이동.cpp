#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int n, r, c;
queue<int> ans;
int map[MAX][MAX];
int dr[] = {-1, 1, 0, 0}; // 우선순위 : 상, 하, 좌, 우
int dc[] = {0, 0, -1, 1};

void input(){
    cin >> n >> r >> c;
    r--; c--;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
}

void solution(){
    bool flag;
    int nr, nc;
    ans.push(map[r][c]);

    do{
        flag = false;
        for(int d=0; d<4; d++){
            nr = r+dr[d];
            nc = c+dc[d];
            if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
            if(map[r][c]<map[nr][nc]){
                flag = true;
                r = nr; 
                c = nc;
                ans.push(map[r][c]);
                break;
            }
        }

    }while(flag);
}

void output(){
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}