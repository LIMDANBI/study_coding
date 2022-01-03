#include <iostream>
using namespace std;

int arr[1001][1001]={};
int visit[1001]={};
int n, m; 

void dfs(int num){
    visit[num]=1;
    for(int i=1; i<=n; i++){
        if(!visit[i] && arr[num][i]) dfs(i);
    }
}

int main(){
    int a, b, ans=0; cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        arr[a][b]=1; arr[b][a]=1;  
    }
    for(int i=1; i<=n; i++){
        if(!visit[i]) {
            ans++;
            dfs(i);
        }
    }
    cout<<ans;
}