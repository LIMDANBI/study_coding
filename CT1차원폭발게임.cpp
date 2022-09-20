#include<iostream>
#include<cstring>
#define MAX 101
using namespace std;

int N, M, len, map[MAX];

void input(){
    cin >> N >> M; len=N;
    for(int i=0; i<N; i++) cin >> map[i];
}

int getEndIdx(int start_idx){
    int end_idx = start_idx+1;
    while(end_idx < len){
        if(map[end_idx]==map[start_idx]) end_idx++;
        else break;
    }
    return end_idx-1;
}

void cutMap(int start_idx, int end_idx){
    int cut_len = end_idx-start_idx+1;
    for(int i = end_idx+1; i<len; i++) map[i-cut_len] = map[i];
    len-=cut_len;
}

void solution(){
    int cur_idx;
    bool flag;

    do{
        cur_idx = 0;
        flag = false;

        while(cur_idx < len){
            int end_idx = getEndIdx(cur_idx);
            if(end_idx-cur_idx+1>=M){
                cutMap(cur_idx, end_idx);
                flag = true;
            } 
            else cur_idx = end_idx+1;
        }
    } while(flag);
}

void output(){
    cout << len << "\n";
    for(int i=0; i<len; i++) cout << map[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}