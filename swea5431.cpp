#include<iostream>
#include<cstring>
#define MAX 101
using namespace std;

int N, K;
bool isSubmit[MAX];

void input(){
    
    // for init
    memset(isSubmit, false, sizeof(isSubmit));

    cin >> N >> K;
    for(int i=0; i<K; i++){
        int num; cin >> num;
        isSubmit[num] = true;
    }
}

void output(int t){
    cout << "#" << t << " ";
    for(int i=1; i<=N; i++){
        if(!isSubmit[i]) cout << i << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        input();
        output(t);
    }
}