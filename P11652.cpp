#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, long long>a, pair<int, long long>b) {
	if (a.first == b.first) { return a.second < b.second;}
	return a.first > b.first;
}
int main(){
    vector<long long> N; vector<pair<int, long long>> num; int n, idx=0; cin>>n; long long input;
    for (int i=0; i<n; i++) { cin>>input; N.push_back(input);} sort(N.begin(), N.end()); num.push_back(make_pair(1, N[0]));
    for (int i=1; i<n; i++) {
        if(N[i]==N[i-1]) num[idx].first++;
        else {num.push_back(make_pair(1, N[i])); idx++;}
    } sort(num.begin(), num.end(), compare); cout<<num[0].second;
}