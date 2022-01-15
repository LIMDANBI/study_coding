#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int num[9], ans[9];

void backtracking(int from, int cnt){
    if(cnt==M){ // 조건의 맞춰 M개 선택을 완료 
        for(int i=0; i<M; i++) cout << ans[i] << ' '; // 저장해 놓은 값 출력
        cout << '\n';
        return;
    }
    int prevnum = -1;
    for(int i=from; i<=N; i++){
        if(prevnum != num[i]){ // 이전 수와 같지 않은 경우
            ans[cnt] = num[i]; // 수 결정
            prevnum = num[i]; // 이전 수 update
            backtracking(i, cnt+1); // 다음 수를 결정 (같은 수 고를 수 o)
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++) cin>>num[i];
    sort(num, num+N+1); // 사전 순으로 증가하는 순서로 출력하기 위해 정렬
    backtracking(1, 0);
}