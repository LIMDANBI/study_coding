#include<iostream>
#include<cstring>
#include<queue>
#define MAX 65
using namespace std;

int N, Q, L;
int remain_ice=0,largest_mass=0;
int A[MAX][MAX];
bool visit[MAX][MAX], reduce[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int pow2[] = {1, 2, 4, 8, 16, 32, 64};

void fireStorm(){
    for(int i=1; i<=N; i+=L){ // 시계 방향 회전
        for(int j=1; j<=N; j+=L){
            queue<int> q;
            int endR = i+L;
            int endC = j+L;
            for(int r=i; r<endR; r++){
                for(int c=j; c<endC; c++) q.push(A[r][c]);
            }
            for(int c=endC-1; c>=j; c--){
                for(int r=i; r<endR; r++){
                    A[r][c] = q.front();
                    q.pop();
                }
            }
        }
    }

    memset(reduce, false, sizeof(reduce)); // 감소 여부 false로 초기화
    for(int y=1; y<=N; y++){ // 얼음양 감소
        for(int x=1; x<=N; x++){
            int cnt=0;
            for(int d=0; d<4; d++){
                int ny = y+dy[d];
                int nx = x+dx[d];
                if(ny<1 || ny>N || nx<1 || nx>N || A[ny][nx]==0) continue; // 범위를 벗어나거나 얼음이 없는 경우
                cnt++; 
            }
            if(cnt<3 && A[y][x]>0) reduce[y][x] = true; // 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 경우, 감소 여부 true
        }
    }
    for(int y=1; y<=N; y++){
        for(int x=1; x<=N; x++){
            if(reduce[y][x]) A[y][x]--;
        }
    }
}

void bfs(int i, int j){ // largest_mass
    int res = 1;
    queue<pair<int, int>> q;
    visit[i][j]=true;
    q.push({i, j});
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<1 || ny>N || nx<1 || nx>N || visit[ny][nx] || A[ny][nx]<1) continue; // 범위를 벗어나는 경우, 이미 방문한 경우, 얼음이 없는 경우
            visit[ny][nx] = true;
            q.push({ny, nx});
            res++;
        }
    }
    largest_mass = max(largest_mass, res);
}

void ans(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) {
            remain_ice+=A[i][j]; // remain_ice
            if(!visit[i][j] && A[i][j]) bfs(i, j); // largest_mass
        }
    }
    cout << remain_ice << '\n' << largest_mass;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q; N = pow2[N];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cin >> A[i][j];
    }
    while(Q--){ // 파이어스톰을 Q번 시전
        cin >> L; L= pow2[L];
        fireStorm();
    }
    ans(); // remain_ice와 largest_mass를 구하고 출력
}