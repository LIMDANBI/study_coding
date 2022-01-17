//[풀이 1] dfs를 이용한 풀이
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

//[풀이 2] dp를 이용한 풀이
#include<iostream>
#include<cstring>
#define MAX_N 17
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int home[MAX_N][MAX_N], dp[MAX_N][MAX_N][3];
    memset(dp, 0, sizeof(dp)); // 초기화 
    dp[1][2][0]=1; // 초기화 
    
    int N; cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cin >> home[i][j];
    }
    for(int i=1; i<=N; i++){ // dp (반복문을 돌면서 값을 하나씩 update해나감)
        for(int j=3; j<=N; j++){
            if(home[i][j]) continue;
            dp[i][j][0] = dp[i][j-1][0]+dp[i][j-1][2]; // 가로
            dp[i][j][1] = dp[i-1][j][1]+dp[i-1][j][2]; // 세로
            if(!home[i-1][j] && !home[i][j-1]) // 대각선의 경우 추가 검사 필요
                dp[i][j][2] = dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2]; // 대각선
            else dp[i][j][2]=0;
        }
    }
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2]; // 가로, 세로, 대각선 도착 가짓수을 모두 더하면 총 도착 가짓수
}