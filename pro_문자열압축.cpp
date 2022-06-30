#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = s.length();
    int len=s.length();
    int cnt, start;
    string res = "", prev="";
    for(int unit=1; unit<=len/2; unit++){ // 문자를 몇 개 단위로 자를지
        prev = s.substr(0, unit); // 이전 문자열 묶음
        res = ""; // 압축된 문자열
        cnt=1, start=0;
        for(start=unit; start<len; start+=unit){
            string tmp = s.substr(start, unit);
            if(prev == tmp) cnt++;
            else{
                if(cnt!=1) res+=to_string(cnt); // 문자가 반복되지 않아 한번만 나타난 경우 1은 생략
                res+=prev;
                cnt=1;
                prev=tmp;
            }
        }
        if(cnt>1) res+=to_string(cnt);
        res+=prev;
        int res_len = res.length();
        answer = min(answer, res_len);
    }
    return answer;
}