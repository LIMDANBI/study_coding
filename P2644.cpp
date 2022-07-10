#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

int n, m, p1, p2;
vector<int> v[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p1 >> p2 >> m;
    int x, y;
    while (m--){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = -1;

    cout << ans;
}