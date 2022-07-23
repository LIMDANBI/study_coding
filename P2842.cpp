#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define MAX 51
#define INF 987654321
using namespace std;

int N, home=0;
int py, px;
set<int> setAltitude;
vector<int> vecAltitude;
char village[MAX][MAX];
int altitude[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 수평, 수직, 대각선 이동 가능
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

void input(){
    cin >> N;
    for(int i=0; i<N; i++){ // 마을 
        string tmp; cin >> tmp;
        for(int j=0; j<N; j++){
            village[i][j] = tmp[j]; 
            if(village[i][j] == 'P'){
                py=i; px=j;
            }
            if(village[i][j] == 'K') home++; // 집 개수
        }
    }
    for(int i=0; i<N; i++){ // 고도
        for(int j=0; j<N; j++) {
            cin >> altitude[i][j];
            setAltitude.insert(altitude[i][j]);
        }
    }
}

bool bfs(int low, int high){ // low~high 고도 안에서 방문 가능 여부를 반환
    if(low > altitude[py][px] || high < altitude[py][px]) 
        return false; // low~high 고도 내에 우체국의 고도가 포함되지 않는 경우
    memset(visited, false, sizeof(visited)); // 방문 여부 초기화

    queue<pair<int, int>> q;
    visited[py][px] = true; q.push({py,px}); // 우체국에서 출발
    int viist_home = 0;
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<8; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=N || nx<0 || nx>=N) continue; // 범위를 벗어나는 경우
            if(visited[ny][nx]) continue; // 이미 방문한 경우
            if(altitude[ny][nx]<low || altitude[ny][nx]>high) continue; // low~high 고도 내에 포함되지 않는 경우
            visited[ny][nx] = true;
            q.push({ny, nx});
            if(village[ny][nx] == 'K') viist_home++;
        }
    }
    if(home == viist_home) return true; // low~high 고도 내에서 모든 집에 배달이 가능한 경우
    return false; // low~high 고도 내에서 모든 집에 배달이 불가능한 경우
}

int solution(){
    for(auto iter: setAltitude) vecAltitude.push_back(iter);
    sort(vecAltitude.begin(), vecAltitude.end()); // 중복 없는 고도 정렬

    int low=0, high=0, ans = INF;
    while (high < vecAltitude.size()){ // 두 포인터 
        int vlow = vecAltitude[low];
        int vhihg = vecAltitude[high];
        if(bfs(vlow, vhihg)) {
            ans = min(ans, vhihg-vlow);
            low++;
        }
        else high++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    cout << solution();
}