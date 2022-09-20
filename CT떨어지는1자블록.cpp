#include<iostream>
#define MAX 101
using namespace std;

int n, m, k;
int map[MAX][MAX];

void input(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> map[i][j];
    }
}

void solution(){
    int row;
    for(row=1; row<=n; row++){
        int flag = false;
        for(int col=k; col<=k+m-1; col++){
            if(map[row][col]) flag=true;
        }
        if(flag) break;
    }
    for(int col=k; col<=k+m-1; col++) map[row-1][col] = 1;
}

void output(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout << map[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}