#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int, int>> v;
    vector<int> ans(1000001);
    for(int i=0; i<n; i++){
        int tmp; cin>>tmp;
        v.push_back(make_pair(tmp, i));
    }
    sort(v.begin(), v.end());
    int c = 0;
    for(int i=0; i<=n-1; i++){
        if(i!=0 && v[i].first == v[i-1].first) c--;
        ans[v[i].second] = c++;
    }
    for(int i=0; i<n; i++) cout << ans[i] << ' ';
}