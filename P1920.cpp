#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1; 
vector<int> v2;

int binarySearch(int x){
    int low= 0, high = v1.size()-1;
    while (low<=high){
        int mid = (low+high)/2;
        if(x == v1[mid]) return mid;
        else if(x < v1[mid]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    int n, m, ipt; 
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ipt;
        v1.push_back(ipt);
    }
    sort(v1.begin(), v1.end());
    
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>ipt;
        v2.push_back(ipt);
    }
    
    for(int i=0; i<m; i++){
        if(binarySearch(v2[i])==-1) cout<< 0 << '\n';
        else cout << 1 << '\n';
    }
}