#include <iostream>
#include <stack>
#define MAX 80000
using namespace std;

stack<int> s;
int building[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> building[i];

    long long ans=0;
    for(int i=0; i<n; i++){
        while (!s.empty() && s.top()<=building[i]) s.pop(); // 높거나 같은 빌딩부터 다음 옥상들은 보지 못함
        ans+=(long long)s.size();
        s.push(building[i]);
    }
    cout << ans;
}