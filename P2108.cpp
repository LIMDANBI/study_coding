#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first==b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(){
    int n, tmp, sum=0, isin=0, idx; cin >> n;
    vector<int> num; vector<pair<int, int>> frequency;
    for(int i=0; i<n; i++){
        cin >> tmp; sum+=tmp; num.push_back(tmp);
        for(int j=0; j<frequency.size(); j++){
            if(frequency[j].second == tmp) {isin=1; idx=j; break;}
        }
        if(isin) frequency[idx].first++;
        else frequency.push_back(make_pair(1, tmp));
        isin=0;
    }
    sort(num.begin(), num.end());
    sort(frequency.begin(), frequency.end(), compare);
    cout << fixed; cout.precision(0);
    cout << sum/(double)n << '\n';
    cout << num[n/2] <<'\n';
    if(frequency[0].first == frequency[1].first) cout << frequency[1].second << '\n';
    else cout << frequency[0].second << '\n';
    cout << num[n-1]-num[0] << '\n';
}