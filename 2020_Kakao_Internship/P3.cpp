#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> m;
    for(auto gem:gems) m[gem] = 0;
    int start=0, end=0; // 투 포인터
    int tmp_s=0, tmp_e=0;
    int kind=m.size(), cur_kind=0; // 보석 종류
    int len = 1e9;
    while (1){
        if(cur_kind==kind){
            if(end-start<len){
                tmp_s = start;
                tmp_e = end;
                len = end-start;
            }
            if(m[gems[start]]>1){
                m[gems[start]]--;
                start++;
            }
            else{
                m[gems[start]]--;
                start++;
                cur_kind--;
            }
        }
        else{
            if(end==gems.size()) break;
            if(!m[gems[end]]) cur_kind++;
            m[gems[end]]++;
            end++;
        }
    }
    answer.push_back(tmp_s+1);
    answer.push_back(tmp_e);
    return answer;
}