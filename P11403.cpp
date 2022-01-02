#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int path[101][101];
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> path[i][j];
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!path[i][j] && path[i][k] && path[k][j]) path[i][j] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout << path[i][j] << ' ';
        cout << '\n';
    }
}