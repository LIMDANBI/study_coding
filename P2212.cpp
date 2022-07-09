#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10001
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, K, tmp, ans=0;
    cin >> N >> K;
    vector<int> sensor;
    for(int i=0; i<N; i++){
        cin >> tmp;
        sensor.push_back(tmp);
    }
    sort(sensor.begin(), sensor.end());
    vector<int> dist;
    for(int i=1; i<N; i++) dist.push_back(sensor[i]-sensor[i-1]);
    sort(dist.begin(), dist.end());
    for(int i=0; i<N-K; i++) ans+=dist[i];
    cout << ans;
}