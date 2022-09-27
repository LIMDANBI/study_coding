#include<iostream>
#define MAX 100001
using namespace std;

int n, arr[MAX];

int solution(int target){
    int low=0, mid, high=n-1;
    int lower_bound = n;

    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]>=target){
            high = mid-1;
            lower_bound = min(lower_bound, mid);
        }
        else low = mid+1;
    }
    if(arr[lower_bound]!=target) return -1;
    else return lower_bound+1; // 배열의 idx는 0부터 시작
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, target; cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    while(m--){
        cin >> target;
        cout << solution(target) << "\n";
    }
}