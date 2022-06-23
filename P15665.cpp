#include<iostream>
#include<algorithm>
using namespace std;

int N, M, num[8], ans[8];

void backtracking(int cnt){
    if(cnt == M){ // M 개를 모두 선택한 경우
        for(int i=0; i<M; i++) 
            cout << ans[i] << " ";
        cout << "\n";
        return ;
    }
    int prev = -1; // 직전에 고른 수 
    for(int i=0; i<N; i++){
        if(prev == num[i]) continue; // 중복되는 수열을 여러 번 출력하면 안됨
        prev = num[i];
        ans[cnt] = num[i];
        backtracking(cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> num[i];
    sort(num, num+N);
    backtracking(0);
}