#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, s, t; 
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for(int i=1; i<v.size(); i++){
        if(pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        }
        else pq.push(v[i].second);
    }
    cout << pq.size();
}