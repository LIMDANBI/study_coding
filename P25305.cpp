#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;

int N, k, score[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> k;
    for(int i=0; i<N; i++) cin >> score[i];
    sort(score, score+N);
    cout << score[N-k];
}