#include<iostream>
#define MAX 51
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    char map[MAX][MAX];
    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<M; j++) map[i][j] = map[j];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]=='.') continue;
            map[i][M-j-1] = map[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << map[i][j];
        cout << '\n';
    }
}