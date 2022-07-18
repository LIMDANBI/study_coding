#include<iostream>
#define MAX 21
using namespace std;

int N, M, map[MAX][MAX];

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> map[i][j];
    }
}

int gold_mining(int y, int x, int k){
    int res = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(abs(y-i)+abs(x-j)<=k) res+=map[i][j];
        }
    }
    return res;
}

int solution(){
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<=2*(N-1); k++){
                int gold = gold_mining(i, j, k);
                int cost = k*k+(k+1)*(k+1); 
                if(cost<=gold*M) ans = max(ans, gold);
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    int ans = solution();
    cout << ans;
}