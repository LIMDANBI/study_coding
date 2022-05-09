#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long ans[3];
vector<long long> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        long long tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end()); // 정렬
    
    long long value = 3000000001;
    for(int low=0; low<N-2; low++){ // low 고정
        int mid=low+1, high=N-1;
        while (mid<high){ // mid, high 바꿔가며 0에 가장 가까운 용액을 만들어내는 세 용액의 특성값을 찾음
            long long res = v[low]+v[mid]+v[high];
            if(abs(res) < value){
                value = abs(res);
                ans[0] = v[low];
                ans[1] = v[mid];
                ans[2] = v[high];
            }
            if(res<0) mid++;
            else high--;
        }
    }
    for(int i=0; i<3; i++) cout << ans[i] << " ";
}