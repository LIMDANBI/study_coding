#include<iostream>
#define MAX 100001
using namespace std;

int n, arr[MAX];

int lower_bound(int target){
    int lower = n;
    int low=0, mid, high=n-1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]>=target){
            high = mid-1;
            lower = min(lower, mid);
        }
        else low = mid+1;
    }
    return lower;
}

int upper_bound(int target){
    int upper = n;
    int low=0, mid, high=n-1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]>target){
            high = mid-1;
            upper = min(upper, mid);
        }
        else low = mid+1;
    }
    return upper;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, target;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    while(m--){
        cin >> target;
        cout << upper_bound(target)-lower_bound(target) << "\n";
    }
}