#include<iostream>
#define MAX_N 15
using namespace std;

int N, ans, board[MAX_N];

int promising(int r){ // 유망한지 판단
    for(int i=0; i<r; i++){
        if(board[r]==board[i] || r-i == abs(board[r]-board[i])) // 같은 열, 대각선에 있으는 경우
            return 0;
    }
    return 1;
}

void backtracking(int r){
    if(r==N){
        ans++; 
        return;
    }
    for(int c=0; c<N; c++){
        board[r] = c; // r열 c행에 queen을 놓아봄
        if(promising(r)) // 유망한 경우
            backtracking(r+1); // 다음 행에 퀸을 놓아봄
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    backtracking(0);
    cout << ans;
}