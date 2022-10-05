#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 21
#define INF 987654321
using namespace std;

int n, ans=INF;
int total_pop=0;
int population[5];
int map[MAX][MAX];
bool border[MAX][MAX];

int dy[] = {-1, -1, 1, 1};
int dx[] = {1, -1, -1, 1};

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
            total_pop+=map[i][j];
        }
    }
}

bool in_range(int y, int x){
    return 0<=y && y<n && 0<=x && x<n;
}

bool possible_draw(int y, int x, int w, int h){ // 모든 꼭지점이 전부 범위 내에 있어야 함
    return in_range(y-w, x+w) && in_range(y-w-h, x+w-h) && in_range(y-h, x-h);
}

int get_diff(int y, int x, int w, int h){

    // 초기화 
    memset(border, false, sizeof(border));
    memset(population, 0, sizeof(population));

    // 경계 표시
    int move_num[] = {w, h, w, h};
    for(int d=0; d<4; d++){
        for(int i=0; i<move_num[d]; i++){
            y+=dy[d]; x+=dx[d];
            border[y][x] = true;
        }
    }

    // 좌측 상단
    for(int i=0; i<y-h; i++){
        for(int j=0; j<=x+w-h && !border[i][j]; j++) population[0]+=map[i][j];
    }

    // 좌측 하단
    for(int i=y-h; i<n; i++){
        for(int j=0; j<x && !border[i][j]; j++) population[1]+=map[i][j];
    }

    // 우측 상단
    for(int i=0; i<=y-w; i++){
        for(int j=n-1; j>x+w-h && !border[i][j]; j--) population[2]+=map[i][j];
    }

    // 우측 하단
    for(int i=y-w+1; i<n; i++){
        for(int j=n-1; j>=x && !border[i][j]; j--) population[3]+=map[i][j];
    }

    population[4] = total_pop-population[0]-population[1]-population[2]-population[3];
    sort(population, population+5); // 정렬
    return population[4]-population[0]; // 최대 - 최소 
}

void solution(){
    for(int y=1; y<n; y++){
        for(int x=1; x<n; x++){
            for(int w=1; w<n; w++){
                for(int h=1; h<n; h++){
                    if(possible_draw(y,x,w,h)) ans = min(ans, get_diff(y,x,w,h));
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << ans;
}