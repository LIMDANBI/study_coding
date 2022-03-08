#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 101
using namespace std;

int N, root[MAX];
vector<pair<double, double> > stars;
vector<pair<double, pair<int, int> > > line;

int find(int x){
    if(x==root[x]) return x;
    return root[x] = find(root[x]);
}

void union_(int x, int y){
    root[find(x)] = find(y);
}

double dist(double x, double y, double x2, double y2){
    return sqrt(pow(x2-x, 2)+pow(y2-y, 2));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<N; i++) root[i] = i; // 초기화
    double x, y, ans=0; cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        stars.push_back({x, y});
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            double cost = dist(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
            line.push_back(make_pair(cost, make_pair(i, j)));
        }
    }
    sort(line.begin(), line.end());

    for(int i=0; i<line.size(); i++){
        int s1 = line[i].second.first;
        int s2 = line[i].second.second;
        double cost = line[i].first;
        if(find(s1)!=find(s2)){
            union_(s1, s2);
            ans+=cost;
        }
    }
    cout.precision(3); 
    cout << ans;
}