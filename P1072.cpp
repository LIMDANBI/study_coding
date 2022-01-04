#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long x, y; cin >> x >> y;
    long long z = y*100/x;
    if(99<=z) cout << -1;
    else{
        long long low=0, high=1000000000;
        while (low<=high){
            long long mid = (low+high)/2;
            int tmpz = ((y+mid)*100)/(x+mid);
            if(z<tmpz) high=mid-1;
            else low=mid+1;
        }
        cout << low;
    }
}