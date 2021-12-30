#include <iostream>
using namespace std;

int network[101][101] = {};
int visit[101] = {};
int computerNum, ans=0;

void dfs(int n){
    ans++;
    visit[n]=1;
    for(int i=1; i<computerNum+1; i++){
        if(network[n][i] && !visit[i]) dfs(i);
    }

}

int main(){
    int pairNum, a, b;
    cin >> computerNum;
    cin >> pairNum;
    for(int i=0; i<pairNum; i++){
        cin >> a >> b;
        network[a][b]=1; network[b][a]=1;
    }
    dfs(1);
    cout << ans-1;
}