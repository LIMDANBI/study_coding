#include<iostream>
#define MAX 100001
using namespace std;

int n, m, num, arr[MAX];

int solution(int num){
    int low=1, mid, high=n;
    
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==num) return mid;
        if(arr[mid]<num) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> arr[i];
    while(m--) {
        cin >> num;
        cout << solution(num) << "\n";
    }
}