#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    priority_queue<int> maxheap, minheap;
    
    for(int i=0; i<n; i++){
        int num; cin>>num;
        if(minheap.size() < maxheap.size()) minheap.push(-num);
        else maxheap.push(num);

        if(!minheap.empty() && !maxheap.empty()){
            if (-minheap.top() < maxheap.top()){
                int maxtop = maxheap.top();
                int mintop = -minheap.top();
                maxheap.pop(); minheap.pop();
                maxheap.push(mintop); minheap.push(-maxtop);
            }
        }
        cout << maxheap.top() <<'\n';
    }
}