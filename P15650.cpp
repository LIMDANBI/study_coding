#include<iostream>
using namespace std;

int n, m;
int num[9]={};
bool visit[9]={false};

void backtracking(int from, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++) cout << num[i] << ' ';
        cout<<'\n';
        return;
    }
    for(int i=from; i<=n; i++){
        if(!visit[i]){
            visit[i] = true;
            num[cnt] = i;
            backtracking(i+1, cnt+1);
            visit[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    backtracking(1, 0);
}