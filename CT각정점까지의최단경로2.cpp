#include<iostream>
#define MAX 101
#define INF 987654321
using namespace std;

int n, m;
int floyd[MAX][MAX];

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) floyd[i][j] = 0;
            else floyd[i][j] = INF;
        }
    }
}

void input(){
    cin >> n >> m;
    init();
    int i, j, cost;
    while(m--){
        cin >> i >> j >> cost; i--; j--;
        floyd[i][j] = min(cost, floyd[i][j]);
    }
}

void solution(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) 
                floyd[i][j] = min(floyd[i][j], floyd[i][k]+floyd[k][j]);
        }
    }
}

void output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(floyd[i][j]==INF) cout << "-1 ";
            else cout << floyd[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}