#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, s, tmp; cin>>n>>s;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    int low=0, high=0, sum=0, ans=n+1, cnt=0;
    while(1){
        if(s<=sum){
            if(cnt<ans) ans=cnt;
            sum-=v[low++]; cnt--;
        }
        else if(n<=high) break;
        else {
            sum+=v[high++];
            cnt++;
        }
    }
    if(ans==n+1) cout << 0;
    else cout << ans;
}