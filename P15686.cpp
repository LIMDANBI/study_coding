#include<iostream>
#include<vector>
#include<cmath> // abs()
#define MAX 51
#define INF 987654321
using namespace std;

int N, M, ans=INF;
bool is_select[13];
vector<pair<int, int> > chicken, home, selected;

void find(){ // '도시의 치킨 거리' 최소값을 찾음
    int res = 0;
    for(int i=0; i<home.size(); i++){
        int dist = INF;
        for(int j=0; j<selected.size(); j++){
            int manhattan = abs(home[i].first-selected[j].first)+abs(home[i].second-selected[j].second);
            dist = min(dist, manhattan);
        }
        res+=dist;
    }
    ans = min(ans, res);
}


void choose(int idx, int m){ // brute-force : 치킨집 고르기
    if(m == 0) // 치킨 집을 다 고른 경우
        return find(); // '도시의 치킨 거리' 최소값을 찾음
    for(int i=idx; i<chicken.size(); i++){ // 치킨 집을 덜 고른 경우
        if(!is_select[i]){ // 선택하지 않은 것 중 선택 !
            is_select[i] = true;
            selected.push_back({chicken[i].first, chicken[i].second}); // 선택한 치킨 집의 좌표 저장
            choose(i+1, m-1); // 더 선택해야 하는지 탐색하고 선택해야 하면 선택!
            is_select[i] = false; // 선택이 끝나고 나온 뒤 선택을 해제!
            selected.pop_back(); // 저장했던 좌표도 pop 해준다!
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tmp; cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) {
            cin >> tmp;
            if(tmp==1) home.push_back({i, j}); // 집들의 위치 저장
            if(tmp==2) chicken.push_back({i, j}); // 치킨집들의 위치 저장
        }
    }
    choose(0, M); // 치킨집을 고르고,  '도시의 치킨 거리' 최소값을 계산
    cout << ans;
}