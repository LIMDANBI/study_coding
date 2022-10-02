#include<iostream>
#include<vector>
#include<queue>
#define MAX 21
using namespace std;

struct LIKE{int n1, n2, n3, n4;};
struct priority{int like, empty, row, col;};
struct compare{ // 우선순위 : 좋아하는 친구 > 빈칸 > 작은 행 번호 > 작은 열 번호
    bool operator()(const priority &p1, const priority &p2){ // operator method 재정의
        if(p1.like==p2.like){
            if(p1.empty==p2.empty){
                if(p1.row==p2.row) return p1.col > p2.col;
                return p1.row > p2.row;
            } return p1.empty < p2.empty;
        } return p1.like < p2.like;
    }
};

int n;
int map[MAX][MAX];
vector<int> order;
vector<LIKE> friends(MAX*MAX);

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void input(){
    cin >> n;
    int n0, n1, n2, n3, n4;
    for(int i=0; i<n*n; i++){
        cin >> n0 >> n1 >> n2 >> n3 >> n4;
        friends[n0] = {n1, n2, n3, n4};
        order.push_back(n0);
    }
}

void solution(){
    int n0, n1, n2, n3, n4, like, empty;
    for(int i=0; i<n*n; i++){
        priority_queue<priority, vector<priority>, compare> pq;
        n0 = order[i];
        n1 = friends[n0].n1;
        n2 = friends[n0].n2;
        n3 = friends[n0].n3;
        n4 = friends[n0].n4;
        // cout << n0 << n1 << n2 << n3 << n4 <<"\n";
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                like=0; 
                empty=0;
                for(int d=0; d<4; d++){
                    int ny=y+dy[d];
                    int nx=x+dx[d];
                    if(ny<0 || ny>=n || nx<0 || nx>=n) continue; // 범위를 벗어나는 경우
                    if(map[ny][nx]==0) empty++; // 빈칸 
                    if(map[ny][nx]==n1 || map[ny][nx]==n2 || map[ny][nx]==n3 || map[ny][nx]==n4) like++; // 좋아하는 친구
                }
                // cout << like << empty << y << x << "\n";
                if(map[y][x] == 0)pq.push({like, empty, y, x});
            }
        }
        int row = pq.top().row;
        int col = pq.top().col;
        // cout << "\n" << row << col << "\n";
        map[row][col] = n0;
    }
}

void print_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << map[i][j] << " ";
        cout <<"\n";
    }
}

void output(){
    int ans=0;
    int n0, n1, n2, n3, n4, like;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            like = 0;
            n0 = map[y][x];
            n1 = friends[n0].n1;
            n2 = friends[n0].n2;
            n3 = friends[n0].n3;
            n4 = friends[n0].n4;
            for(int d=0; d<4; d++){
                int ny=y+dy[d];
                int nx=x+dx[d];
                if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if(map[ny][nx]==n1 || map[ny][nx]==n2 || map[ny][nx]==n3 || map[ny][nx]==n4) like++;
            }
            if(like<2) ans+=like;
            else if(like==2) ans+=10;
            else if(like==3) ans+=100;
            else if(like==4) ans+=1000;
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    // print_map();
    output();
}