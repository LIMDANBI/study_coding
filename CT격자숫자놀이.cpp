#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define MAX 101
#define CNT 0
#define TMP 1
using namespace std;

int r, c, k, rnum=3, cnum=3;
int cnt[MAX], map[MAX][MAX], tmp_map[MAX][MAX];

void input(){
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++) cin >> map[i][j];
    }
}

void init(int what){
    if(what == CNT){ // 초기화 
        for(int i=1; i<MAX; i++) cnt[i]=0;
    }
    else if(what == TMP) memset(tmp_map, 0, sizeof(tmp_map)); // 초기화 
}

void copy(){
    for(int i=1; i<MAX; i++){
        for(int j=1; j<MAX; j++) map[i][j] = tmp_map[i][j];
    }
    memset(tmp_map, 0, sizeof(tmp_map)); // 초기화 
}

void print_map(){
    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++) cout << map[i][j] << " ";
        cout  << "\n";
    }
}

void play(){
    init(TMP);
    int tmp_cnum=cnum, tmp_rnum=rnum;
    if(rnum>=cnum){ // 행의 개수가 열의 개수보다 크거나 같은 경우
        for(int row=1; row<=rnum; row++){
            init(CNT);
            for(int col=1; col<=cnum; col++) cnt[map[row][col]]++; // 출현빈도 수 
            vector<pair<int, int>> v; // 출현빈도수, 숫자
            for(int col=1; col<MAX; col++){
                if(cnt[col]==0) continue;
                v.push_back({cnt[col], col});
            }
            sort(v.begin(), v.end()); // 오름차순 정렬
            int col = 1;
            for(int i=0; i<(int)v.size(); i++){
                if(col>100) continue;
                tmp_map[row][col] = v[i].second; col++; // 숫자
                tmp_map[row][col] = v[i].first; col++; // 출현빈도수
            }
            tmp_cnum = max(tmp_cnum, col-1); // cnum update
        }
        cnum = tmp_cnum;
    }
    else{ // 행의 개수가 열의 개수보다 작은 경우
        for(int col=1; col<=cnum; col++){
            init(CNT);
            for(int row=1; row<=cnum; row++) cnt[map[row][col]]++; // 출현빈도 수 
            vector<pair<int, int>> v; // 출현빈도수, 숫자
            for(int row=1; row<MAX; row++){
                if(cnt[row]==0) continue;
                v.push_back({cnt[row], row});
            }
            sort(v.begin(), v.end()); // 오름차순 정렬
            int row = 1;
            for(int i=0; i<(int)v.size(); i++){
                if(row>100) continue;
                tmp_map[row][col] = v[i].second; row++; // 숫자
                tmp_map[row][col] = v[i].first; row++; // 출현빈도수
            }
            tmp_rnum = max(tmp_rnum, row-1); // cnum update
        }
        rnum = tmp_rnum;
    }
    copy();
    // cout << rnum << " is tmp_rnum \n";
    // print_map(); cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    int ans =0;
    while(map[r][c]!=k && ans<100){
        play();
        ans++;
    }
    if(ans==100) cout << -1;
    else cout << ans;
}