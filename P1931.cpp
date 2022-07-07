#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, start, end, ans=1; cin >> N;
    vector<pair<int, int>> meeting;
    for(int i=0; i<N; i++){
        cin >> start >> end;
        meeting.push_back({start, end});
    }
    sort(meeting.begin(), meeting.end());

    int prev_end = meeting[0].second;
    for(int i=1; i<N; i++){
        start = meeting[i].first;
        end = meeting[i].second;
        if(end<prev_end) prev_end = end; // 더 일찍 끝나는 회의 선택
        else if(prev_end<=start){ // 다음 회의
            ans++;
            prev_end = end;
        }
    }
    cout << ans;
}