#include<iostream>
using namespace std;

int N, d, k, c;
int arr[30001], cnt[3001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> d >> k >> c; // 벨트에 놓인 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
    for(int i=0; i<N; i++) cin >> arr[i];

    int kind=0, max_kind=0; // 먹을 수 있는 초밥 가짓수
    for(int i=0; i<k; i++){
        if(cnt[arr[i]]==0) kind++; // 새로운 초밥 종류
        cnt[arr[i]]++;
    } 
    if(cnt[c]==0) max_kind = kind+1; // 쿠폰으로 새로운 종류의 초밥을 먹을 수 있음
    else max_kind = kind;

    int l=0, r=k;
    while(l < N){ // 두 포인터를 하나씩 움직여가며 탐색
        if(cnt[arr[l]]==1) kind--; // 초밥 종류 감소
        cnt[arr[l]]--;
        if(cnt[arr[r]]==0) kind++; // 초밥 종류 증가
        cnt[arr[r]]++;
        if(cnt[c]==0) max_kind = max(max_kind, kind+1);
        else max_kind = max(max_kind, kind);
        l++; r++; r%=N;
    }
    cout << max_kind;
}