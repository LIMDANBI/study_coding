# include <iostream>
# include <algorithm>
using namespace std;

int main(){
    int k, n; cin>>k>>n;
    int cable[k];
    for(int i=0; i<k; i++)
        cin>>cable[i];
    sort(cable, cable+k);
    long long low = 0, high = cable[k-1];
    long long mid = (low+high)/2;

    while (low<=high){
        int num = 0;
        for(int i=0; i<k; i++){
            if(mid==0) mid=1;
            num+=cable[i]/mid;
        }
        if(num<n) high = mid-1;
        else low = mid+1;
        mid = (low+high)/2;
    }
    if(n==1) cout << cable[0];
    else cout << mid;   
}