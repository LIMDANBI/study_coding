#include<iostream>
using namespace std;

int n, N, M;

int solution(){
    int ans = 1;
    while(M--) ans*=N;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        cin >> n;
        cin >> N >> M;
        cout << "#" << t << " " << solution() << "\n";
    }
}