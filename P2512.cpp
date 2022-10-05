#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;

int N, M;
int budget[MAX];
int max_budget=0;

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> budget[i];
        max_budget = max(max_budget, budget[i]);
    }
    cin >> M;
}

void solution(){
    int ans, sum;
    int low=0, mid, high=max_budget;
    while(low<=high){ 
        sum = 0;
        mid = (low+high)/2;
        for(int i=0; i<N; i++) sum+=min(mid, budget[i]);
        if(sum <= M){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}