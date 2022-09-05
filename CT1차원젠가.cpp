#include<iostream>
#include<cstring>
#define MAX 101
using namespace std;

int n, jenga[MAX], tmp_jenga[MAX];

void input(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> jenga[i];
}

void removeBlock(int s, int e){
    int idx = 0;
    memset(tmp_jenga, 0, sizeof(tmp_jenga));
    for(int i=0; i<n; i++){
        if(s<=i && i<=e) continue;
        tmp_jenga[idx] = jenga[i];
        idx++;
    }
    n-=(e-s+1);
    for(int i=0; i<n; i++){
        jenga[i] = tmp_jenga[i];
    }
}

void solution(){
    for(int i=0; i<2; i++){
        int s, e; cin >> s >> e;
        removeBlock(s-1, e-1);
    }
}

void output(){
    cout << n << "\n";
    for(int i=0; i<n; i++) cout << jenga[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}