#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, x, y; cin >> N;
    vector<pair<int, int>> coordinates;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        coordinates.push_back(make_pair(x, y));
    }
    sort(coordinates.begin(), coordinates.end());
    for(int i=0; i<N; i++) cout << coordinates[i].first << " " << coordinates[i].second << '\n';
}