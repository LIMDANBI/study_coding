#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 101
using namespace std;

int N, root[MAX];
vector<pair<double, double> > stars;
vector<pair<double, pair<int, int> > > line;

int find(int x){ // 두 별이 이어져 있는지 확인하고, 이을 때 사용
    if(x==root[x]) return x;
    return root[x] = find(root[x]);
}

void union_(int x, int y){ // 두 별을 이음
    root[find(x)] = find(y);
}

double dist(double x1, double y1, double x2, double y2){ // 유클리드 거리 계산
    return sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    double x, y, ans=0; 
    cin >> N; 
    for(int i=0; i<N; i++) root[i] = i; // 초기화
    for(int i=0; i<N; i++){ // 별들의 좌표 저장 
        cin >> x >> y;
        stars.push_back({x, y});
    }
    for(int i=0; i<N-1; i++){ // 별들 간 거리 계산
        for(int j=i+1; j<N; j++){
            double cost = dist(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
            line.push_back(make_pair(cost, make_pair(i, j)));
        }
    }
    sort(line.begin(), line.end()); // 크루스칼 알고리즘을 위한 정렬

    for(int i=0; i<line.size(); i++){ // MST를 만듦
        int s1 = line[i].second.first;
        int s2 = line[i].second.second;
        double cost = line[i].first;
        if(find(s1)!=find(s2)){ // 연결되지 않은 경우 
            union_(s1, s2); // 연결
            ans+=cost; // 비용을 더해줌
        }
    }
    cout.precision(3); // 출력 자릿수 고정
    cout << ans; // 최소 비용 출력
}