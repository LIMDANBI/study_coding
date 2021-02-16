#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
 	if (a.first.first == b.first.first) return a.first.second < b.first.second;
 	return a.first.first > b.first.first;
}
int main(){
    int k; cin>>k;
    for(int i=1; i<=k; i++){
        int M,N,P; cin>>M>>N>>P; int mistake[501][11]{};
        vector<pair<pair<int, int>, int>> output(P); for(int l=0; l<P; l++) output[l].second=l+1;
        while(N--) { 
            int p,t,j; char m; cin>>p>>m>>t>>j;
            if(j && mistake[p-1][m-64]!=-1) { 
                output[p-1].first.second+=(t+mistake[p-1][m-64]*20); mistake[p-1][m-64]=-1; output[p-1].first.first++;
            } else if(j==0 && mistake[p-1][m-64]!=-1) mistake[p-1][m-64]++;
        } sort(output.begin(), output.end(), compare); cout<<"Data Set "<<i<<":"<<'\n';
        for(int l=0; l<P; l++) cout<<output[l].second<<" "<<output[l].first.first<<" "<<output[l].first.second<<'\n'; cout<<'\n';
    }
}