#include<iostream>
#define MAX 50
using namespace std;

int N;
int arr[MAX][MAX];

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        string line; cin >> line;
        for(int j=0; j<N; j++) arr[i][j] = line[j]-'0';
    }
}

int solution(){
    int ans = 0;
    int mid = N/2;

    // mid
    for(int i=0; i<N; i++) ans+=arr[mid][i];

    int cnt = 1;
    int up, down;
    while(1){
        up = mid-cnt;
        down = mid+cnt;
        if(N-2*cnt<1) break; // 종료 조건
        for(int i=cnt; i<N-cnt; i++) {
            ans+=arr[up][i]; // up
            ans+=arr[down][i]; // down
        }
        cnt++;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}