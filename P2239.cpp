#include<iostream>
#include<vector>
using namespace std;

int sdoku[9][9];
vector<pair<int, int> > v;

bool promising(int r, int c, int k){
    for(int i=0; i<9; i++){ // 가로 확인 
        if(i == c) continue;
        if(sdoku[r][i]==k) return false;
    }
    for(int i=0; i<9; i++){ // 세로 확인 
        if(i == r) continue;
        if(sdoku[i][c]==k) return false;
    }
    // 3x3 사각형 확인
    int nr=r/3*3 , nc=c/3*3;
    for(int i=nr; i<nr+3; i++){
        for(int j=nc; j<nc+3; j++){
            if(nr==r && nc==c) continue;
            if(sdoku[i][j] == k) return false;
        }
    }
    return true;
}

void backtracking(int idx){
    if(idx == v.size()){ // 모든 빈칸을 채운 경우
        for(int i=0; i<9; i++){ // 결과 출력
            for(int j=0; j<9; j++) cout << sdoku[i][j];
            cout << '\n';
        }
        exit(0);
    }
    int r = v[idx].first, c = v[idx].second;
    for(int k=1; k<=9; k++){
        if(!promising(r, c, k)) continue;
        sdoku[r][c] = k; // 유망한 경우 해당 숫자를 넣어봄
        backtracking(idx+1); // 다음 빈칸에 알맞은 숫자 탐색
        sdoku[r][c] = 0; // backtracking
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string nums;
    for(int i=0; i<9; i++){ // 입력 받기
        cin >> nums;
        for(int j=0; j<9; j++){
            sdoku[i][j] = nums[j]-'0';
            if(sdoku[i][j]==0) v.push_back({i, j});
        }
    }
    backtracking(0);
}