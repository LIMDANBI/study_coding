#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, m, arr[MAX];

int upper_bound(int target){
    int low=0, mid, high=n-1, res=n;
    while(low<=high){
        mid = (low+high)/2;
        if(target<arr[mid]){
            high = mid-1;
            res = min(res, mid);
        }
        else low = mid+1;
    }
    return res;
}

int lower_bound(int target){
    int low=0, mid, high=n-1, res=n;
    while(low<=high){
        mid = (low+high)/2;
        if(target<=arr[mid]){
            high = mid-1;
            res = min(res, mid);
        }
        else low = mid+1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n); // 정렬

    int s, e;
    while(m--){
        cin >> s >> e;
        cout << upper_bound(e)-lower_bound(s) << "\n";
    }
}