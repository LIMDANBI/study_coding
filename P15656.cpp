#include<iostream>
#include<algorithm>
#define MAX 8
using namespace std;

int N, M;
int num[MAX], ans[MAX];

void backtracking(int cnt){
    if(cnt == M){ // 모든 자리를 설정한 경우 
        for(int i=0; i<M; i++) cout << ans[i] << ' '; // 출력
        cout << '\n';
        return ; // 종료
    }
    for(int i=0; i<N; i++){
        ans[cnt] = num[i]; // 해당 자리를 설정
        backtracking(cnt+1); // 다음 자리를 설정
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> num[i];
    sort(num, num+N); // 사전 순으로 증가하는 순서로 출력하기 위해서
    backtracking(0);
}