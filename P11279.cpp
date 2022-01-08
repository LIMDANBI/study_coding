#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    priority_queue<int> pq;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int tmp; cin>>tmp;
        if(tmp == 0){
            if(pq.empty()) cout << 0 << '\n';
            else {
                int top = pq.top(); pq.pop();
                cout << top << '\n';
            }
        }
        else pq.push(tmp);
    }
}