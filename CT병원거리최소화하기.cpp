#include<iostream>
#include<vector>
#define PERSON 1
#define HOSPITAL 2
#define MAX 51
#define INF 987654321
using namespace std;

int n, m, ans=INF;
vector<pair<int, int>> person, hospital, selected_hospital;

void input(){
    int tmp; cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cin >> tmp;
            if(tmp==PERSON) person.push_back({i,j});
            if(tmp==HOSPITAL) hospital.push_back({i,j});
        }
    }
}

void solution(int cnt, int idx){
    if(cnt==m){
        int res = 0;
        for(int i=0; i<(int)person.size(); i++){
            int py = person[i].first;
            int px = person[i].second;
            int min_dist = INF;
            for(int j=0; j<(int)selected_hospital.size(); j++){
                int hy = selected_hospital[j].first;
                int hx = selected_hospital[j].second;
                min_dist = min(min_dist, abs(hy-py)+abs(hx-px));
            }
            res+=min_dist;
        }
        ans = min(ans, res);
        return;
    }
    for(int i=idx; i<(int)hospital.size(); i++){
        selected_hospital.push_back(hospital[i]);
        solution(cnt+1, i+1);
        selected_hospital.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution(0, 0);
    cout << ans;
}