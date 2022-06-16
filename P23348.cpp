#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A, B, C; cin >> A >> B >> C;
    int N; cin >> N;
    int a, b, c, ans=0, max_val=0;
    for(int i=1; i<=3*N; i++){
        cin >> a >> b >> c;
        max_val+=(A*a+B*b+C*c);
        if(i%3==0){
            ans = max(ans, max_val);
            max_val = 0;
        }
    }
    cout << ans;
}