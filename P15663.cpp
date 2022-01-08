#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int num[9]{};
int ans[9]{};
bool visit[9]={false};

void backtracking(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    int prev_num = -1;
    for(int i=1; i<=n; i++){
        if(!visit[i] && prev_num!=num[i]){
            visit[i] = true;
            ans[cnt] = num[i];
            prev_num = num[i];
            backtracking(cnt+1);
            visit[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>num[i];
    sort(num, num+n+1);
    backtracking(0);
}