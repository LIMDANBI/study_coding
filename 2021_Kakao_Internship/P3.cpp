#include <string>
#include <vector>
#include <stack>
using namespace std;

struct DATA{
    int num;
    bool isdelecte;
};

vector<DATA> v;
stack<int> s;
int cur, last;

void upSelect(int x){ // 현재 선택된 행에서 X칸 위에 있는 행을 선택
    while (x){
        cur--;
        if(!v[cur].isdelecte) x--;
    }
}

void downSelect(int x){ // 현재 선택된 행에서 X칸 아래에 있는 행을 선택
    while (x){
        cur++;
        if(!v[cur].isdelecte) x--;
    }
}

void delecte(){ // 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택 (삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택)
    v[cur].isdelecte = true;
    s.push(cur);
    if(cur == last){
        while (!v[cur].isdelecte) cur--;
    }
    else{
        while (!v[cur].isdelecte) cur++;
    }
    last = cur;
}

void restore(){ // 가장 최근에 삭제된 행을 원래대로 복구 (현재 선택된 행은 바뀌지 x)
    int row = s.top(); s.pop();
    v[row].isdelecte = false;
    if(row>last) last = row;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    cur = k; last=n-1;
    for(int i=0; i<n; i++) v.push_back({i, false});
    for(int c=0; c<cmd.size(); c++){
        if(cmd[c][0]=='U') upSelect(stoi(cmd[c].substr(2, cmd[c].length()-1)));
        else if(cmd[c][0]=='D') downSelect(stoi(cmd[c].substr(2, cmd[c].length()-1)));
        else if(cmd[c][0]=='C') delecte();
        else if(cmd[c][0]=='Z') restore();
    }
    for(int i=0; i<n; i++){
        if(v[i].isdelecte) answer+="X";
        else answer+="O";
    }
    return answer;
}