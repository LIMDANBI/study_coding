#include<iostream>
#include<deque>
using namespace std;
int main(){
    int n; deque<int> card; cin>>n; for(int i=1; i<=n; i++) card.push_back(i);
    while (!card.empty()){
        cout<<card.front()<<" "; card.pop_front();
        if(!card.empty()) {int tmp=card.front(); card.pop_front(); card.push_back(tmp);}
    }
}