#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 21
using namespace std;

struct Data{int like, empty, row, col;};
struct Like{int like1, like2, like3, like4;};

bool compare(Data a, Data b){
    if(a.like == b.like){
        if(a.empty == b.empty){
            if(a.row == b.row) return a.col < b.col; // 열의 번호가 가장 작은 칸
            return a.row < b.row; // 행의 번호가 가장 작은 칸
        }
        return a.empty > b.empty; // 인접한 칸 중에서 비어있는 칸이 가장 많은 칸
    }
    return a.like > b.like; // 좋아하는 학생이 인접한 칸에 가장 많은 칸
} 

int ans = 0; // 만족도 합
int classroom[MAX][MAX];
Like likeFriend[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, student, like1, like2, like3, like4;
    cin >> N;
    for(int i=0; i<N*N; i++){
        cin >> student >> like1 >> like2 >> like3 >> like4; // 학생, 학생이 좋아하는 학생 4명
        
        vector<Data> v;
        for(int r=1; r<=N; r++){ // 자리 설정
            for(int c=1; c<=N; c++){
                int like_cnt=0, empty_cnt=0;
                for(int d=0; d<4; d++){ // 좋아하는 인접 학생, 인접 빈칸 계산
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr<1 || nr>N || nc<1 || nc>N) continue; // 범위를 벗어나는 경우
                    if(classroom[nr][nc] == like1 || classroom[nr][nc] == like2 || classroom[nr][nc] == like3 ||classroom[nr][nc] == like4) like_cnt++; // 좋아하는 인접 학생
                    if(classroom[nr][nc] == 0) empty_cnt++; // 인접 빈칸
                }
                v.push_back({like_cnt, empty_cnt, r, c});
            }
        }
        sort(v.begin(), v.end(), compare); // 주어진 3가지 조건에 맞추어 정렬
        for(int j=0; j<v.size(); j++){
            if(!classroom[v[j].row][v[j].col]) { // 학생이 없는 경우에
                classroom[v[j].row][v[j].col] = student; // 자리 배정
                likeFriend[v[j].row][v[j].col] = {like1, like2, like3, like4};
                break;
            }
        }
    }
    for(int r=1; r<=N; r++){ // 만족도 계산
        for(int c=1; c<=N; c++){
            int like_cnt=0;
            for(int d=0; d<4; d++){ // 좋아하는 인접 학생, 인접 빈칸 계산
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr<1 || nr>N || nc<1 || nc>N) continue; // 범위를 벗어나는 경우
                    if(classroom[nr][nc] == likeFriend[r][c].like1 || classroom[nr][nc] == likeFriend[r][c].like2 || classroom[nr][nc] == likeFriend[r][c].like3 ||classroom[nr][nc] == likeFriend[r][c].like4) like_cnt++; // 좋아하는 인접 학생
            }
            if(like_cnt==4) ans+=1000;
            else if(like_cnt==3) ans+=100;
            else if(like_cnt==2) ans+=10;
            else ans+=like_cnt;
        }
    }
    cout << ans;
}