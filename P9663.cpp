#include <iostream>
#define MAX 15
using namespace std;

int N, ans, board[MAX];

bool promising(int r){
    for(int i=1; i<r; i++){
        if(board[r]==board[i] || r-i == abs(board[r]-board[i])) return false; // 같은 열, 대각선에 있는 경우
    }
    return true;
}

void backtracking(int r){
    if(r==N+1){
        ans++;
        return ;
    }
    for(int c=1; c<=N; c++){
        board[r] = c; // r열 c행에 queen을 놓아봄
        if(promising(r)) backtracking(r+1); // 유망한 경우 다음 행에 퀸을 놓음
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    backtracking(1);
    cout << ans;
}