#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A, B, C, D, E, ans=0;
    cin >> A >> B >> C >> D >> E;
    if(A<0){
        int ice_status = 0-A;
        ans+=ice_status*C;
        ans+=D;
        ans+=B*E;
    }
    else ans+=(B-A)*E;
    cout << ans;
}