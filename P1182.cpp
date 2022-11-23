#include<iostream>
#define MAX 21
using namespace std;

int N, S;
int ans = 0;
int num[MAX];

void input(){
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> num[i];
}

void solution(int cnt, int sum){
    if(cnt == N) {
        if(sum == S) ans++;
        return;
    }
    solution(cnt+1, sum+num[cnt]);
    solution(cnt+1, sum);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution(0, 0);
    if(S==0) ans--; // S가 0인 경우는 모든 경우를 선택하지 않는 경우를 빼줘야 함
    cout << ans; // 합이 S가 되는 부분수열의 개수
}