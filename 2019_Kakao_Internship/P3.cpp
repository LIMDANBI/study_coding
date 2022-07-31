#include <string>
#include <vector>
#include <set>
using namespace std;

bool ismatch[8]; // match 되었는지
set<string> check; // 중복 여부 체크
vector<string> ui, bi;

void dfs(int idx){
    if(idx==bi.size()){ // m가지 선택을 완료한 경우
        string use="";
        for(int i=0; i<ui.size(); i++){ // match된 사용자들 번호를 문자열로 만든 후
            if(ismatch[i]) use+=(i+'0');
        }
        check.insert(use); // 집합을 이용하여 중복 문제 해결
        return ;
    }
    for(int i=0; i<ui.size(); i++){
        if(ismatch[i]) continue; // 이미 match된 경우
        string uid = ui[i];
        string bid = bi[idx];
        if(uid.size()!=bid.size()) continue; // 길이가 같지 않으면 대응할 수 없음

        bool iscorrespond = true; // uid와 bid가 대응하는지
        for(int i=0; i<uid.size(); i++){
            if(bid[i]!='*' && uid[i]!=bid[i]) { // 대응되지 않는 경우 
                iscorrespond = false;
                break;
            }
        }

        if(!iscorrespond) continue;
        ismatch[i] = true; // 대응되므로 대응 여부 true로 변환 
        dfs(idx+1); // dfs 탐색
        ismatch[i] = false; // 대응 여부 다시 false로 변환 (다른 탐색을 위해)
    }
}

int solution(vector<string> user_id, vector<string> banned_id) { // nCm (제한사항이 작으므로 brute-force 방식으로 문제를 해결)
    ui = user_id;
    bi = banned_id;
    dfs(0);
    int answer = check.size();
    return answer;
}