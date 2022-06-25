#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i=0; i<(int)scoville.size(); i++) pq.push(-scoville[i]);
    while(1){
        if(K <= -pq.top()) break; // 모든 음식의 스코빌 지수가 K 이상이 된 경우
        answer++;
        int food1 = -pq.top(); pq.pop();
        if(pq.empty()) return -1; // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
        int food2 = -pq.top(); pq.pop();
        int new_food = food1+food2*2;
        pq.push(-new_food);
    }
    return answer;
}