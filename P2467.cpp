#include<iostream>
#define MAX 100001
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, solution[MAX]; cin >> N;
    for(int i=0; i<N; i++) cin >> solution[i];
    int low=0, high=N-1; // 배열의 양 끝 두 포인터
    int ans1=solution[low], ans2=solution[high], min_value = 2147483647;
    while (low<high){
        int mix = solution[low]+solution[high];
        if(abs(mix)<min_value){ // mix 값의 절대값이 더 작은 경우 update
            min_value = abs(mix); 
            ans1 = solution[low]; 
            ans2 = solution[high];
        }
        if(mix<0) low++; // 음수인 경우 low++
        else high--; // 양수인 경우 high--
    }
    cout << ans1 << ' ' << ans2;
}