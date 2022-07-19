#include <iostream>
#include <cstring>
#define MAX 21
using namespace std;

int N, map[MAX][MAX];

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> map[i][j];
    }
}

int sum_rectangle(int y, int x, int w, int h){
    int ny = y, nx = x;
    int ans = map[ny][nx];
    for(int i=0; i<w; i++){ // 우상 
        ny--; nx++;
        if(ny<0 || ny>=N || nx<0 || nx>=N) return 0;
        ans+=map[ny][nx];
    }
    for(int i=0; i<h; i++){ // 좌상
        ny--; nx--;
        if(ny<0 || ny>=N || nx<0 || nx>=N) return 0;
        ans+=map[ny][nx];
    }
    for(int i=0; i<w; i++){ // 좌하
        ny++; nx--;
        if(ny<0 || ny>=N || nx<0 || nx>=N) return 0;
        ans+=map[ny][nx];
    }
    for(int i=0; i<h-1; i++){  // 우하
        ny++; nx++;
        if(ny<0 || ny>=N || nx<0 || nx>=N) return 0;
        ans+=map[ny][nx];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int w=1; w<N-1; w++){
                for(int h=1; h<N-1; h++) 
                    ans = max(ans, sum_rectangle(i,j,w,h));
            }
        }
    }
    cout << ans;
}