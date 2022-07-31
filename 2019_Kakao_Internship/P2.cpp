#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    set<int> check; // 중복 체크
    vector<pair<int, vector<int>>> lenAndNum;
    
    int len=0;
    string strnum="";
    vector<int> nums;
    
    for(int i=1; i<s.size()-1; i++){ // 집합의 길이와 원소 저장
        if(s[i]=='{') continue;
        else if(s[i]=='}'){
            nums.push_back(stoi(strnum));
            strnum = "";
            lenAndNum.push_back({len, nums});
            len = 0;
            nums.clear();
        }
        else if(s[i]==','){
            if(s[i-1]=='}') continue;
            nums.push_back(stoi(strnum));
            len++;
            strnum = "";
        }
        else strnum+=s[i]; // 숫자
    }
    
    sort(lenAndNum.begin(), lenAndNum.end()); // 정렬
    
    for(auto lan: lenAndNum){ // 중복 원소인지 체크하면서 순서대로 넣어줌
        for(auto num: lan.second){
            if(check.count(num)!=0) continue;
            check.insert(num);
            answer.push_back(num);
        }
    }
    return answer;
}