#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, num; cin >> N;
    int ans = -N+1;
    for(int i=0; i<N; i++) {
        cin >> num;
        ans+=num;
    }
    cout << ans;
}