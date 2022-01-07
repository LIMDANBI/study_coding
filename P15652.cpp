#include<iostream>
using namespace std;

int n, m;
int num[9]{};
int visit[9]{};

void backtracking(int from, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++) cout << num[i] << ' ';
        cout << '\n';
        return ;
    }
    for(int i=from; i<=n; i++){
        if(visit[i]<m){
            visit[i]++;
            num[cnt] = i;
            backtracking(i, cnt+1);
            visit[i]--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    backtracking(1, 0);
}