#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer; // 당첨 가능한 최고 순위와 최저 순위를 차례대로 배열에 담아서 return
    int match=0, zero=0;
    int num[46]; memset(num, 0, sizeof(num));
    for(int i=0; i<6; i++) num[win_nums[i]] = 1;
    for(int i=0; i<6; i++){
        if(num[lottos[i]]) match++;
        if(lottos[i]==0) zero++;
    }
    int ranking[] = {6, 6, 5, 4, 3, 2, 1};
    answer.push_back(ranking[match+zero]);
    answer.push_back(ranking[match]);
    return answer;
}