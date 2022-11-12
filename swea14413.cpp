#include<iostream>
#include<queue>
#define MAX 51
using namespace std;

int N, M;
// int qmark;
char arr[MAX][MAX];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
queue<pair<int, int>> q;

void input(){

    // init 
    while(!q.empty()) q.pop();

    string line;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> line;
        for(int j=0; j<M; j++) {
            arr[i][j] = line[j];
            if(arr[i][j]=='#' || arr[i][j]=='.') q.push({i, j}); // black, white 
        }
    }
}

string solution(){

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue; // out of range
            if(arr[y][x] == arr[ny][nx]) return "impossible"; // same color
            if(arr[ny][nx]!='?') continue; // not question mark
            if(arr[y][x]=='#') arr[ny][nx] = '.';
            else arr[ny][nx] = '#';
            q.push({ny, nx});
        }
    }

    return "possible";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}