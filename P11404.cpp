#include <iostream>
using namespace std;

int cost[101][101]={};
const int INF = 999999999;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    int i, j, c;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i==j) cost[i][j]=0;
            else cost[i][j]=INF;
        }
    }
    for(int k=0; k<m; k++){
        cin >> i >> j >> c;
        cost[i][j] = min(cost[i][j], c);
    }
    for(int k=1; k<=n; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++) {
            if(cost[i][j]==INF) cout << 0 << ' ';
            else cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}