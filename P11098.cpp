#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p, c;
    string name;
    cin >> n;
    while (n--){
        cin >> p;
        vector<pair<int, string>> v;
        for(int i=0; i<p; i++){
            cin >> c >> name;
            v.push_back({c, name});
        }
        sort(v.begin(), v.end());
        cout << v[p-1].second << '\n';
    }
}