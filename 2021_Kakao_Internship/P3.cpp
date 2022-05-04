#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

stack<Node*> s;
Node *header, *cur;

void init(int n, int k){
    header = new Node();
    header->data = 0;
    header->prev = NULL;
    header->next = NULL;
    cur = header;
    for(int i=1; i<n; i++){
        Node *n = new Node();
        n->data = i;
        cur->next = n;
        n->prev = cur;
        n->next = NULL;
        cur = n;
    }
    cur = header;
    for(int i=0; i<k; i++) cur = cur->next;
}

void upSelect(int x){ // 현재 선택된 행에서 X칸 위에 있는 행을 선택
    while (x--) cur = cur->prev;
}

void downSelect(int x){ // 현재 선택된 행에서 X칸 아래에 있는 행을 선택
    while (x--) cur = cur->next;
}

void delecte(){ // 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택 (삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택)
    s.push(cur);
    if(cur->prev==NULL){
        cur = cur->next;
        cur->prev = NULL;
        header = cur;
    }
    else if(cur->next==NULL){
        cur = cur->prev;
        cur->next = NULL;
    }
    else{
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur = cur->next;
    }
}

void restore(){ // 가장 최근에 삭제된 행을 원래대로 복구 (현재 선택된 행은 바뀌지 x)
    Node *n = s.top(); s.pop();
    if(n->prev==NULL){
        n->next->prev = n;
        header = n;
    }
    else if(n->next==NULL){
        n->prev->next = n;
    }
    else{
        n->prev->next = n;
        n->next->prev = n;
    }
}

void solution(vector<string> cmd){
    for(int i=0; i<cmd.size(); i++){
        if(cmd[i][0]=='U') upSelect(stoi(cmd[i].substr(2)));
        else if(cmd[i][0]=='D') downSelect(stoi(cmd[i].substr(2)));
        else if(cmd[i][0]=='C') delecte();
        else if(cmd[i][0]=='Z') restore();
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for(int i=0; i<n; i++) answer+="X";
    init(n, k);
    solution(cmd);
    cur = header;
    while (1){
        answer[cur->data] = 'O';
        cur = cur->next;
        if(cur == NULL) break;
    }
    return answer;
}