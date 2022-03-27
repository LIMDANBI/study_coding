#include <iostream>
#include<cstring>
#include <vector>
#include<queue>
#define MAX 105
using namespace std;

struct pos{int r, c;};

int N, K, ans=0;
int fishbowl[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void addFish(){ // 물고기 수가 가장 적은 어항에 물고기 한 마리 추가
    vector<pos> v;
    int min_value = 1e9;
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            if(fishbowl[r][c]==0) continue;
            if(fishbowl[r][c] < min_value){ // 물고기 수가 더 적은 어항인 경우 
                min_value = fishbowl[r][c]; // 최솟값 update
                v.clear(); // 기존의 저장해둔 위치들을 비워주고,
                v.push_back({r, c}); // 해당 최솟값의 위치 저장
            }
            else if(fishbowl[r][c] == min_value) v.push_back({r, c}); // 최솟값이 두개 이상일 수 o
        }
    }
    for(int i=0; i<v.size(); i++) fishbowl[v[i].r][v[i].c]++; // 물고기 수가 가장 적은 어항에 물고기 한마리 씩 추가 
}

void build(){ // 어항 쌓기
    int pivot=1, w=1, h=1; // 기준점, 너비, 높이
    for(int idx=0; ; idx++){
        if(pivot-1+w+h > N) break; // 더 이상 쌓을 수 없는 경우
        for(int c=pivot; c<pivot+w; c++){
            for(int r=N; r>N-h; r--){ // 계방향으로 90도 회전시켜 어항을 쌓음
                int nr = (N-w) + (c-pivot);
                int nc = (pivot+w) + (N-r);
                fishbowl[nr][nc] = fishbowl[r][c];
                fishbowl[r][c] = 0;
            }
        }
        pivot+=(idx/2+1); // 기준점 위치 변경
        idx%2 ? w++ : h++; // 번갈아가며 증가하는 규칙을 가짐
    }
}

void controlFish(){ // 물고기 수 조절
    int copy_fishbowl[MAX][MAX] = {0}; // 물고기가 이동을 기록할 임시 배열
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            if(fishbowl[r][c] == 0) continue;
            copy_fishbowl[r][c]+=fishbowl[r][c];
            for(int i=0; i<4; i++){ // 인접한 어항에 대해, 물고기 수 차이를 구함
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(fishbowl[nr][nc] == 0) continue;
                if(fishbowl[r][c] > fishbowl[nr][nc]){
                    int d = (fishbowl[r][c] - fishbowl[nr][nc]) / 5;
                    copy_fishbowl[r][c]-=d; // (r, c)에서 (nr, nc)로 물고기 d 마리를 보냄
                    copy_fishbowl[nr][nc]+=d;
                }
            }
        }
    }
    memcpy(fishbowl, copy_fishbowl, sizeof(copy_fishbowl)); // 배열 복사
}

void flatten(){ // 어항 일렬로 펼치기
    queue<int> q;
    for(int c=1; c<=N; c++){ // 규칙에따라 queue에 순서대로 저장
        if(fishbowl[N][c]==0) continue;
        for(int r=N; r>0; r--){
            if(fishbowl[r][c]==0) break;
            q.push(fishbowl[r][c]);
            fishbowl[r][c] = 0;
        }
    }
    int c=1;
    while (!q.empty()){ // queue에 순서대로 저장해두었던 것을 일렬로 펼쳐줌
        fishbowl[N][c++] = q.front();
        q.pop();
    }
}

void fold(){ // 어항 2번 접기
    int num = N/4;
    int col[4] = {0, N, N-num+1, N}; // 옮겨지는 시작 위치
    int dir[4] = {0, -1, 1, -1}; // 1 : -> , -1 : <-

    int idx = 1;
    for(int i=1; i<4; i++){
        int c = col[i];
        for(int j=0; j<num; j++){
            fishbowl[N-i][c] = fishbowl[N][idx];
            fishbowl[N][idx] = 0;
            c+=dir[i]; idx++;
        }
    }
}

int diff(){ // max - min 값 반환
    int max_value = 0;
    int min_value = 1e9;
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            if(fishbowl[r][c]==0) continue;
            max_value = max(max_value, fishbowl[r][c]);
            min_value = min(min_value, fishbowl[r][c]);
        }
    }
    return max_value-min_value;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int c=1; c<=N; c++) cin >> fishbowl[N][c]; // 물고기 수 입력
    while (1){ // max-min <= K 일 때까지 어항 정리
        if(diff() <= K) break;
        addFish();

        build();
        controlFish();
        flatten();
        
        fold();
        controlFish();
        flatten();
        
        ans++;
    } cout << ans;
}