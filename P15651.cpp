#include<iostream>
using namespace std;

int n, m;
int num[8]={};
int visit[8]={};

void backtracking(int cnt){
    if(cnt==m){
        for(int i=0; i<m; i++) cout << num[i] << ' ';
        cout <<'\n'; 
        return;
    }
    for(int i=1; i<=n; i++){
        if(visit[i]<m){
            visit[i]++;
            num[cnt] = i;
            backtracking(cnt+1);
            visit[i]--;
        }
    }
}

int main(){
    cin>>n>>m;
    backtracking(0);
}