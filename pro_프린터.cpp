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
    pair<int, int> tmp;
    while(!q.empty()){
        if(q.front().first == pq.top() && q.front().second == location) break;
        else if(q.front().first == pq.top()){
            q.pop();
            pq.pop();
            answer++;
        }
        else{
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    return answer+1;
}