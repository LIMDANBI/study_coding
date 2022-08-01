#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> room;

long long find(long long n){
    if(room[n]==0) return n;
    return room[n] = find(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
   
    vector<long long> answer;

    for(auto num : room_number){
        if(room[num]==0){ // 방이 비어 있는 경우
            answer.push_back(num); // 해당 방 베정 
            room[num] = find(num+1); // 다시 해당 방을 배정 받기 원하는 손님이 있을 경우, 배정 가능한 가장 작은 빈 방
        }
        else{ // 방이 비어 있지 않은 경우
            long long next = find(num); // 베정할 수 있는 다음 방
            answer.push_back(next); // 다음 방 배정
            room[next] = find(next+1); // 다시 해당 방을 배정 받기 원하는 손님이 있을 경우, 배정 가능한 가장 작은 빈 방
        }
    }
    return answer;
}