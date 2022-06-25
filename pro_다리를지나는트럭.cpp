#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q;
    int idx=0, total=0; // 차량 지목, 다리 위 차의 무게
    
    while(1){
        if(idx == truck_weights.size()){ // 마지막 트럭인 경우
            answer+=bridge_length;
            break;
        }
        answer++;
        if(q.size() == bridge_length){ // 트럭 하나가 다리를 다 건넌 경우
            total-=q.front();
            q.pop();
        }
        
        int truck = truck_weights[idx];
        if(total+truck <= weight){ // 다음 트럭이 다리에 오를 수 있는 경우
            q.push(truck);
            total+=truck;
            idx++;
        }
        else q.push(0);
    }
    return answer;
}