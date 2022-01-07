#include<iostream>
#include<set>
using namespace std;

int n, k;
int card[11]={};
bool visit[11]={false};
set<string> s;

void backtracking(int index, string numStr){
    if(index==k){
        s.insert(numStr);
        return;
    }
    for(int i=0; i<n; i++){
        if(visit[i]==false){
            visit[i] = true;
            backtracking(index+1, numStr+to_string(card[i]));
            visit[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>card[i];
    backtracking(0, "");
    cout << s.size();
}