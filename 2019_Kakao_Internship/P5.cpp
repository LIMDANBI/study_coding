#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> stones, int k) {
    
    int ssize = stones.size();
    multimap<int, int, greater<int>> m; // key의 중복 허용 (stone의 번호가 같을 수 있음)

    for(int i=0; i<k; i++) m.insert({stones[i], i});
    auto max_iter = m.begin(); // m은 key를 기준으로 내림차순 정렬
    int answer = max_iter->first;

    for(int i=0; i<ssize-k; i++){ // sliding window
        auto iter = m.find(stones[i]);
        m.erase(iter);
        m.insert({stones[i+k], i+k});

        max_iter = m.begin();
        answer = min(answer, max_iter->first);
    }
    return answer;
}