#include<iostream>
#include<vector>
using namespace std;

int root[1000001];

int find_(int x){
    if(root[x]==x) return x;
    return root[x] = find_(root[x]);
}

void union_(int a, int b){
    int x = find_(a), y = find_(b);
    if(x<y) root[y] = x;
    else root[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin>>n>>m;
    for(int i=0; i<=n; i++) root[i] = i;
    for(int i=0; i<m; i++){
        int oper, a, b; cin>>oper>>a>>b;
        if(oper == 0) union_(a, b);
        else{
            if(find_(a)==find_(b)) cout << "YES\n";
            else cout << "NO\n";
        } 
    }
}