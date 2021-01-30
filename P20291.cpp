#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n, start; cin>>n; string str;
    vector<string> file; vector<pair<string, int>> ans;
    for(int i=0; i<n; i++){
        cin>>str; start=str.find(".")+1; file.push_back(str.substr(start, str.size()));
    } sort(file.begin(), file.end()); ans.push_back(make_pair(file[0],1)); int idx=0;
    for(int i=1; i<file.size(); i++){
        if(i!=0 && file[i-1]==file[i]) ans[idx].second++;
        else {idx++; ans.push_back(make_pair(file[i], 1));}
    } for(int i=0; i<ans.size(); i++) cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}