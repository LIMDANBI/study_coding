#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n, m, tmp; cin>>n; vector<int> card;
    for(int i=0; i<n; i++) {
        cin>>tmp; card.push_back(tmp);
    } sort(card.begin(), card.end()); cin>>m;
    while(m--){
        cin>>tmp; int low=0, high=card.size()-1, mid=(low+high)/2, isin=0;
        while (low<=high){
            if(card[mid]==tmp){ isin=1; break; }
            else if(card[mid]<tmp) {low=mid+1; mid=(low+high)/2;}
            else {high=mid-1; mid=(low+high)/2;}
        } isin?cout<<1<<" ":cout<<0<<" ";
    }
}