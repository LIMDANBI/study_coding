#include<iostream>
#define MAX 21
using namespace std;

int N, K, ans;
int arr[MAX];

void input(){
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> arr[i];
}

void dfs(int cnt, int sum){
    if(cnt == N){
        if(sum == K) ans++;
        return;
    }
    dfs(cnt+1, sum); // 선택 안하는 경우
    dfs(cnt+1, sum+arr[cnt]); // 선택 하는 경우
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        ans = 0;
        input();
        dfs(0, 0);
        cout << "#" << t << " " << ans << "\n";
    }
}