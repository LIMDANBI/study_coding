#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
bool compare(int a, int b) { return a>b; }
int main(){
    int t, tmp; cin>>t; 
    while(t--){
        int n, m, cnt=1, idx=0; cin>>n>>m; vector<int> priority; queue<pair<int, int>> queue;
        for(int i=0; i<n; i++){ 
            cin>>tmp; priority.push_back(tmp);
            queue.push(make_pair(tmp, i));
        } sort(priority.begin(), priority.end(), compare);
        while(1){
            if(priority[idx]==queue.front().first){
                if(queue.front().second==m) { cout<<cnt<<'\n'; break;}
                else {queue.pop(); cnt++; idx++;}
            } else{
                int a=queue.front().first, b=queue.front().second;
                queue.pop(); queue.push(make_pair(a, b));
            }
        }
    }
}