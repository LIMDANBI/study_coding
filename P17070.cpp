#include<iostream>
#define MAX_N 17
using namespace std;

int N, ans = 0;
int home[MAX_N][MAX_N]; // 집의 상태

void dfs(int y, int x, int state){
    if(N<x || N<y || home[y][x] || (state==2 && (home[y-1][x] || home[y][x-1]))) // 범위를 벗어난 경우, 벽이 있는 경우
        return;
    if(x==N && y==N){ // 파이프 이동 성공
        ans++;
        return;
    }
    if(state==0){ //가로 
        dfs(y, x+1, 0);
        dfs(y+1, x+1, 2);
    }
    else if(state==1){ //세로
        dfs(y+1, x, 1);
        dfs(y+1, x+1, 2);
    }
    else if(state==2){ //대각선
        dfs(y, x+1, 0);
        dfs(y+1, x, 1);
        dfs(y+1, x+1, 2);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cin >> home[i][j];
    }
    dfs(1, 2, 0); // (1, 2) , 가로
    cout << ans;
}