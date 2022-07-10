#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

int T, N, a, b, ans;
vector<pair<int, int>> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
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