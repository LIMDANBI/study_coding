#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 21
using namespace std;

int N;
int arr[MAX][MAX];
vector<pair<int, int>> v;

void input(){
    v.clear(); // init

    string line;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> line;
        for(int j=0; j<N; j++) {
            arr[i][j] = line[j];
            if(arr[i][j] == '#') v.push_back({i, j});
        }
    }
}

string solution(){
    
    // 정렬
    sort(v.begin(), v.end());
    
    int y1 = v[0].first, x1 = v[0].second; // 좌상
    int y2 = v[v.size()-1].first, x2 = v[v.size()-1].second; // 우하
    
    if(v.size() != (y2-y1+1)*(x2-x1+1)) return "no"; // 개수 확인 
    if(y2-y1 != x2-x1) return "no"; // 정사각형 확인

    for(int i=y1; i<=y2; i++){ // 전부 막혀있는지 확인
        for(int j=x1; j<=x2; j++){
            if(arr[i][j]!='#') return "no";
        }
    }
    return "yes";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}