#include<iostream>
#define MAX 500
using namespace std;

int n, map[MAX][MAX];
int dy[] = {0, 1, 0, -1}; // 왼쪽 - 아래쪽 - 오른쪽 - 위쪽
int dx[] = {-1, 0, 1, 0};
int lry[] = {-1, -1, -1, -2, 1, 1, 1, 2};
int lrx[] = {1, 0, -1, 0, 1, 0, -1, 0};
int udy[] = {-1, 0, 1, 0, -1, 0, 1, 0};
int udx[] = {-1, -1, -1, -2, 1, 1, 1, 2};
int rat[] = {1, 7, 10, 2, 1, 7, 10, 2}; 
int ratio2[] = {10, 7, 1, 2, 10, 7, 1, 2}; 

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
}

void print_map(){
    cout <<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << map[i][j] << " ";
        cout << "\n";
    }
}

bool in_range(int y, int x){
    return 0<=y && y<n && 0<=x && x<n;
}

int move_dust(int y, int x, int total_dust, int d){ // 격자 밖으로 떨어진 먼지 양 반환 
    int ny, nx, res=0;
    int amount, a=total_dust;
    map[y][x] = 0; // 청소 

    if(d%2){ // 상, 하
        for(int i=0; i<8; i++){
            ny = y+udy[i];
            nx = x+udx[i];
            if(d==1) amount = total_dust*rat[i]/100;
            if(d==3) amount = total_dust*ratio2[i]/100;
            if(!in_range(ny, nx)) res+=amount;
            else map[ny][nx]+=amount;
            a-=amount;
        }
    }
    else{ // 좌, 우 
        for(int i=0; i<8; i++){
            ny = y+lry[i];
            nx = x+lrx[i];
            if(d==0) amount = total_dust*rat[i]/100;
            if(d==2) amount = total_dust*ratio2[i]/100;
            if(!in_range(ny, nx)) res+=amount;
            else map[ny][nx]+=amount;
            a-=amount;
        }
    }

    // 자기 방향
    ny = y+dy[d]*2;
    nx = x+dx[d]*2;
    amount = total_dust*5/100;
    if(!in_range(ny, nx)) res+=amount;
    else map[ny][nx]+=amount;
    a-=amount;

    ny = y+dy[d];
    nx = x+dx[d];
    if(!in_range(ny, nx)) res+=a;
    else map[ny][nx]+=a;

    return res;
}

void solution(){
    int ans=0;
    int move=0; 
    int y=n/2, x=n/2;
    for(int d=0; x>=0; d++){ d%=4;
        if(d%2==0) move++;
        for(int m=0; m<move; m++){
            y+=dy[d];
            x+=dx[d];
            if(x<0) break;
            ans+=move_dust(y, x, map[y][x], d);
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}