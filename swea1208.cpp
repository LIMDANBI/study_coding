#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;

int cnt; // 덤프 횟수 
int arr[MAX];

void input(){
    cin >> cnt;
    for(int i=0; i<MAX; i++) cin>> arr[i];
}

int solution(){
    while(cnt--){
        sort(arr, arr+MAX);
        arr[MAX-1]--; arr[0]++;
        if(arr[MAX-1]-arr[0]<1) return 0;
    }
    sort(arr, arr+MAX);
    return arr[MAX-1]-arr[0];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}