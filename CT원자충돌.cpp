#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

struct ATOM{int m, s, d;};
vector<ATOM> atom[MAX][MAX], tmp_atom[MAX][MAX];

int N, M, K;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}; // ↑, ↗, →, ↘, ↓, ↙, ←, ↖ 
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void input(){
    cin >> N >> M >> K;
    int y, x, m, s, d; // 위치, 질량, 속력, 방향
    while(M--){
        cin >> y >> x >> m >> s >> d;
        atom[y-1][x-1].push_back({m, s, d});
    }
}

void copy_and_init(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            atom[i][j] = tmp_atom[i][j];
            tmp_atom[i][j].clear();
        }
    }
}

void move_atom(int y, int x){ // 원자의 이동 
    for(int i=0; i<atom[y][x].size(); i++){
        int m = atom[y][x][i].m;
        int s = atom[y][x][i].s;
        int d = atom[y][x][i].d;
        int ny = (y+dy[d]*s+N*s)%N;
        int nx = (x+dx[d]*s+m*s)%N;
        tmp_atom[ny][nx].push_back({m,s,d});
    }
}

void synthesis_atom(int y, int x){
    int new_m=0, new_s=0, new_d=0;
    int tmp=atom[y][x][0].d%2; // 모두 같은 방향에 속하는지 판단할 기준
    int atoms_size = atom[y][x].size();
    for(int i=0; i<atoms_size; i++){
        new_m+=atom[y][x][i].m;
        new_s+=atom[y][x][i].s;
        if(tmp != atom[y][x][i].d%2) new_d=1;
    }
    atom[y][x].clear(); // 기존 정보 비워주고
    new_m/=5; // 질량은 합쳐진 원자의 질량에 5를 나눈 값
    new_s/=atoms_size; // 속력은 합쳐진 원자의 속력에 합쳐진 원자의 개수를 나눈 값
    if(new_m==0) return ;
    for(int d=new_d; d<8; d+=2) atom[y][x].push_back({new_m, new_s, d}); // 합쳐진 원자가 4개의 원자로 나눠짐
}

void solution(){

    // 1. 원자의 이동
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) move_atom(i, j);
    } 
    copy_and_init();

    // 2. 원자의 합성
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(atom[i][j].size()>1) synthesis_atom(i, j); // 원자가 2개 이상 있는 경우 
        }
    }
}

void output(){ // k초 이후 남아있는 원자들의 질량의 합
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int a=0; a<atom[i][j].size(); a++)
                ans+=atom[i][j][a].m;
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    while(K--) solution();
    output();
}