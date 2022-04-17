#include<iostream>
#include<cstring>
#include<vector>
#define MAX 51
using namespace std;

int N, L, R, unionNum, unionSum; // 연합 번호, 연합의 인구수
int A[MAX][MAX], unionArr[MAX][MAX]; // 연합 번호를 저장한 배열
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
vector<pair<int, int>> pos;

void dfs(int r, int c){
    unionArr[r][c] = unionNum; // 연합 번호 부여
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<0 || nr>=N || nc<0 || nc>=N ) continue; // 범위를 벗어나는 경우
        if(unionArr[nr][nc]!=0) continue; // 이미 연합이 정해진 경우 
        int diff = abs(A[r][c]-A[nr][nc]); // 두 나라의 인구 차이
        if(L<=diff && diff<=R){ // 인구 차이가 L명 이상, R명 이하면 국경선 공유
            pos.push_back({nr, nc});
            unionSum+=A[nr][nc]; // 연합의 인구수
            dfs(nr, nc); 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans=0; cin >> N >> L >> R;
    for(int r=0; r<N; r++){ // 각 나라의 인구수 입력
        for(int c=0; c<N; c++) cin >> A[r][c];
    }
    while (1){
        int moveCnt = 0; // 이동 횟수
        memset(unionArr, 0, sizeof(unionArr)); // 초기화
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                if(unionArr[r][c]!=0) continue; // * 이미 연합이 정해진 경우
                unionNum++; // 다음 연합 번호로 업데이트
                pos.clear(); 
                unionSum=A[r][c]; // * 아직 연합이 정해지지 않은 경우, r,c 에서 부터
                pos.push_back({r,c});
                dfs(r, c); // dfs 탐색으로 연합을 정함
                if(pos.size()==1) continue; // 국경선이 모두 닫혀 있는 경우
                moveCnt++; // 이동 횟수 count
                unionSum/=pos.size(); // (연합의 인구수) / (연합을 이루고 있는 칸의 개수)
                for(int i=0; i<pos.size(); i++) A[pos[i].first][pos[i].second] = unionSum;
            }
        }
        if(moveCnt==0) break; // 더 이상 인구 이동이 없는 경우
        ans++;
    }
    cout << ans;
}