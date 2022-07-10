#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, N, a, b, ans; cin >> T;
    vector<pair<int, int>> v;
    while (T--){
        cin >> N;
        ans = 1;
        v.clear();
        for(int i=0; i<N; i++){
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        int high = v[0].second;
        for(int i=1; i<N; i++){
            if(v[i].second < high){
                ans++;
                high = v[i].second;
            }
        }
        cout << ans << "\n";
    }
}