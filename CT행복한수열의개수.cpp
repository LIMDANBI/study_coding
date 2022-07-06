#include<iostream>
#define MAX 101
using namespace std;

int n, m, ans=0;
int map[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
    for(int i=0; i<n; i++){ // 가로
        int cnt = 1;
        int prev = map[i][0];
        for(int j=1; j<n; j++){
            if(map[i][j]==prev) cnt++;
            else{
                if(cnt>=m) break;
                prev = map[i][j];
                cnt=1;
            }
        }
        if(cnt>=m) ans++;
    }
    for(int i=0; i<n; i++){ // 세로
        int cnt = 1;
        int prev = map[0][i];
        for(int j=1; j<n; j++){
            if(map[j][i]==prev) cnt++;
            else{
                if(cnt>=m) break;
                prev = map[j][i];
                cnt=1;
            }
        }
        if(cnt>=m) ans++;
    }
    cout << ans;
}