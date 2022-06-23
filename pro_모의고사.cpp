#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int num1[] = {1,2,3,4,5}; // 1번 수포자가 찍는 방식
    int num2[] = {2,1,2,3,2,4,2,5}; // 2번 수포자가 찍는 방식
    int num3[] = {3,3,1,1,2,2,4,4,5,5}; // 3번 수포자가 찍는 방식
    int idx[] = {0,0,0}; // index
    int len[] = {5,8,10}; // 반복 길이
    int sol[] = {0,0,0}; // 푼 문제
    for(int i=0; i<answers.size(); i++){
        if(num1[idx[0]] == answers[i]) sol[0]++;
        if(num2[idx[1]] == answers[i]) sol[1]++;
        if(num3[idx[2]] == answers[i]) sol[2]++;
        for(int j=0; j<3; j++) idx[j]++;
        for(int j=0; j<3; j++) idx[j]%=len[j];
    }
    int max_val = max(max(sol[0], sol[1]), sol[2]);
    for(int i=0; i<3; i++){
        if(sol[i] == max_val) answer.push_back(i+1);
    }
    return answer;
}