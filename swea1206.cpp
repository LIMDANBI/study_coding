#include<iostream>
#define MAX 1001
using namespace std;

int N, arr[MAX];

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
}

int solution(){
    int ans = 0;
    for(int i=2; i<N-2; i++){
        int h = arr[i];
        int b1 = arr[i-2], b2 = arr[i-1]; // before
        int a1 = arr[i+2], a2 = arr[i+1]; // after
        int tmp = max(a1, max(a2, max(b1, b2)));
        ans += max(0, h-tmp);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}