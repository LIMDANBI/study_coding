#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    for(int i=0; i<(int)priorities.size(); i++){
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        answer++;
        while(!q.empty()){
            int priority = q.front().first;
            int idx = q.front().second;
            if(now == priority){
                q.pop();
                if(location == idx) return answer; // 몇 번째로 출력되는지 알고 싶은 location
                break;
            }
            q.pop();
            q.push({priority, idx});   
        }
    }
}