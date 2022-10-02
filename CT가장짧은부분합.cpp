#include<iostream>
#define MAX 100001
using namespace std;

int n, s, arr[MAX];

void input(){
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];
}

void solution(){
    int left=0, right=0, sum=arr[0], ans=MAX;
    while(right<n){
        if(s<=sum){
            ans = min(ans, right-left+1);
            sum-=arr[left];
            left++;
        }
        else{
            right++;
            sum+=arr[right];
        }
    }
    if(ans==MAX) cout << -1;
    else cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
}