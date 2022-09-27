#include<iostream>
using namespace std;

long long m, a, b;
int short_time=1024, long_time=0;

int solution(long long target){
    int res = 0;
    long long low=1, mid, high=m;
    while(low<=high){
        mid = (low+high)/2; res++;
        if(mid==target) break;
        if(mid<target) low = mid+1;
        else high = mid-1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> a >> b;
    for(long long i=a; i<=b; i++){
        int res = solution(i);
        short_time = min(res, short_time);
        long_time = max(res, long_time);
    }
    cout << short_time << " " << long_time << "\n";
}