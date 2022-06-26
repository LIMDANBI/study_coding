#include<iostream>
#define MAX 100001
using namespace std;

int N, K, ans=0, arr[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    int start=0, sum=0;
    for(int i=0; i<K; i++) sum+=arr[i];
    ans = sum;
    for(int end=K; end<N; end++){
        sum = sum-arr[start]+arr[end];
        ans = max(ans, sum);
        start++;
    }
    cout << ans;
}