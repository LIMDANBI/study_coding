#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, tmp; cin>>n>>m;
    vector<int> v;
    int low=0, high=0;
    for(int i=0; i<n; i++){
        cin>>tmp;
        if(high<tmp) high=tmp;
        v.push_back(tmp);
    }
    while (low<=high){
        long long mid = (low+high)/2;
        long long cutoff = 0;
        for(int i=0; i<n; i++){
            if(v[i]>mid) cutoff+=v[i]-mid;
        }
        if(cutoff>=m) low = mid+1;
        else high = mid-1;
    }
    cout << high;
}