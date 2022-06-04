#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, r, ans=0;
vector<int> rope;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; 
    for(int i=0; i<N; i++){
        cin >> r;
        rope.push_back(r);
    }
    sort(rope.begin(), rope.end());
    int num_rope = (int) rope.size();
    for(int i=0; i<num_rope; i++){
        ans = max(ans, rope[i]*(num_rope-i));
    }
    cout << ans;
}