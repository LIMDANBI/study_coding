#include<iostream>
#define MAX 201
using namespace std;

int N, M;
int map[MAX][MAX];
int shape[6][3][3] = {
    {{1, 1, 0},
    {1, 0, 0},
    {0, 0, 0}},

    {{1, 1, 0},
    {0, 1, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{0, 1, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}},
};

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> map[i][j];
    }
}

int solution(int y, int x){
    int ans = 0;
    for(int s=0; s<6; s++){
        int res = 0;
        bool ispossible = true;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(shape[s][i][j]==0) continue;
                if(y+i>=N || x+j>=M) ispossible=false;
                else res+=map[y+i][x+j];
            }
        }
        if(ispossible) ans = max(res, ans);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) 
            ans = max(ans, solution(i, j));
    }
    cout << ans;
}