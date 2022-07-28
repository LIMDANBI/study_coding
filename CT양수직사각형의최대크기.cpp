#include<iostream>
#define MAX 21
using namespace std;

int N, M;
int map[MAX][MAX];

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> map[i][j];
    }
}

int solution(int i, int j, int w, int h){ // 최대 크기의 양수 직사각형을 찾음
    int res = 0;
    for(int y=i; y<=i+w; y++){
        for(int x=j; x<=j+h; x++){
            if(map[y][x]<=0) return -1;
        }
    }
    return (w+1)*(h+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    int ans = -1;
    for(int w=0; w<N; w++){ // width
        for(int h=0; h<M; h++){ // height
            for(int i=0; i<N-w; i++){ // row
                for(int j=0; j<M-h; j++) ans = max(ans, solution(i, j, w, h)); // col
            }
        }
    }
    cout << ans;
}