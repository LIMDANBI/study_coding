#include<iostream>
using namespace std;

void solution(int s){
    long long low=0, mid, high=s+1, sum, ans=0;
    while(low<=high){
        mid = (low+high)/2;
        sum = mid*(mid+1)/2;
        if(sum<=s){
            ans = max(ans, mid);
            low = mid+1;
        }
        else high = mid-1;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s; cin >> s;
    solution(s);
}