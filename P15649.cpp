#include<iostream>
using namespace std;

int n, m;
int arr[9]={};
bool visit[9]={false};

void backtracking(int idx){
    if(idx==m) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout <<'\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(!visit[i]){
            visit[i] = true;
            arr[idx] = i;
            backtracking(idx+1);
            visit[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    backtracking(0);
}