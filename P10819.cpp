#include<iostream>
#define MAX 10
using namespace std;

int ans = 0, N;
bool checked[MAX];
int arr[MAX], order_arr[MAX];

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
}

int cal(){
    int res = 0;
    for(int i=0; i<N-1; i++) res += abs(order_arr[i]-order_arr[i+1]);
    return res;
}

void solution(int cnt){
    if(cnt == N){
        ans = max(ans, cal());
        return ;
    }
    for(int i=0; i<N; i++){
        if(checked[i]) continue;
        order_arr[cnt] = arr[i];
        checked[i] = true;
        solution(cnt+1);
        checked[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    for(int i=0; i<N; i++){
        checked[i] = true;
        order_arr[0] = arr[i];
        solution(1);
        checked[i] = false;
    }
    cout << ans;
}