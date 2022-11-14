#include<iostream>
#define MAX 10
using namespace std;

int N, ans;
bool arr[MAX][MAX];

bool isPromising(int row, int col){ // 퀸은 같은 행, 열, 또는 대각선 위에 있는 말을 공격할 수 있음
    for(int i=0; i<N; i++){
        if(arr[i][col] ||  arr[row][i]) return false; // check row, col
    }
    for(int i=0; i<N; i++){ // check diagonal
        for(int j=0; j<N; j++){
            if(arr[i][j] && abs(i-row) == abs(j-col)) return false;
        }
    }
    return true;
}

void backtracking(int row){
    if(row == N) {
        ans++;
        return;
    }
    for(int col=0; col<N; col++){
        if(!isPromising(row, col)) continue;
        arr[row][col] = true;
        backtracking(row+1);
        arr[row][col] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        ans = 0;
        cin >> N;
        backtracking(0);
        cout << "#" << t << " " << ans << "\n";
    }
}