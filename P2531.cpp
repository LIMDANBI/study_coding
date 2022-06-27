#include<iostream>
using namespace std;

int N, d, k, c;
int arr[30001], cnt[3001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> d >> k >> c; // 벨트에 놓인 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
    for(int i=0; i<N; i++) cin >> arr[i];

    int kind=0; // 먹을 수 있는 초밥 가짓수
    for(int i=0; i<k; i++){
        cnt[arr[k]]++;
        
    }
}