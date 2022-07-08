#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;

int N, K, map[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> map[i];
    sort(map, map+N);
    
}