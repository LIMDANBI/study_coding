#include<iostream>
#define MAX 51
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    char map[MAX][MAX], c;
    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c;
            if('A'<=map[i][j] && map[i][j]<='Z') continue;
            map[i][j] = c;
            if(c=='.') continue;
            if(j<M/2) map[i][M-j-1] = map[i][j];
            else map[i][j] = map[i][M-j-1];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << map[i][j];
        cout << '\n';
    }
}