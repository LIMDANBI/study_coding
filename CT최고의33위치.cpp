#include<iostream>
#define MAX 21
using namespace std;

int N, ans=0, map[MAX][MAX];

void cntCoin(int y, int x){
    int coin = 0;
    for(int i=y; i<y+3; i++){
        for(int j=x; j<x+3; j++) coin+=map[i][j];
    }
    ans = max(ans, coin);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> map[i][j];
    }
    for(int i=0; i<N-2; i++){
        for(int j=0; j<N-2; j++) cntCoin(i,j);
    }
    cout << ans;
}