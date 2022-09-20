#include<iostream>
#include<cstring>
#define MAX 101
using namespace std;

int N, M, map[MAX], tmp_map[MAX];

void input(){
    cin >> N >> M;
    for(int i=N; i>0; i--) cin >> map[i];
}

void solution(){
    int len=N;
    while(1){
        int idx=1, cnt=1;
        bool flag = true;
        int before = map[1];
        for(int i=2; i<=N; i++){
            if(map[i]==before) cnt++;
            else{
                if(cnt>=M) {
                    flag = false;
                    len-=cnt;
                }
                else{
                    for(int j=0; j<cnt; j++){
                        tmp_map[idx] = before;
                        idx++;
                    }
                }
                before = map[i];
                cnt = 1;
            }
        }
        if(cnt>=M) {
            flag = false;
            len-=cnt;
        }
        else{
            for(int j=0; j<cnt; j++){
                tmp_map[idx] = before;
                idx++;
            }
        }
        N = len;
        for(int i=1; i<=N; i++) map[i] = tmp_map[i];
        memset(tmp_map, 0, sizeof(tmp_map));
        if(flag) break;
    }
}

void output(){
    cout << N << "\n";
    for(int i=N; i>0; i--) cout << map[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}