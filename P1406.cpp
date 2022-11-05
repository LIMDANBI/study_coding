#include <iostream>
using namespace std;

struct node{
    node *prev = NULL;
    node *next = NULL;
    char c;
};

node *head = new node();
node *tail = head;
node *cursor;

void left(){ // 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
    if(cursor != head) cursor = cursor->prev;
}

void right(){ // 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
    if(cursor != tail) cursor = cursor->next;
}

void delete_char(){ // 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
    if(cursor == head) return;
    if(cursor == tail){
        tail = cursor->prev;
        tail->next = NULL;
        cursor = tail;
    }
    else{
        node *prev = cursor->prev;
        node *next = cursor->next;
        prev->next = next;
        next->prev = prev;
        cursor = prev;
    }
}

void add_char(char c){ // 문자 c를 커서 왼쪽에 추가함
    node *n = new node(); // 추가 될 node
    n->c = c;

    if(cursor == tail) tail = n;
    else{
        n->next = cursor->next;
        n->next->prev = n;
    }
    cursor->next = n;
    n->prev = cursor;
    cursor = n;
}

void output(){
    node *n = head->next;
    while(1){
        cout << n->c;
        if(n == tail) break;
        n = n->next; 
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;

    for(int i=0; i<str.size(); i++){
        node *n = new node();
        n->c = str[i];
        n->prev = tail;
        tail->next = n;
        tail = n;
    }

    int M; cin >> M;
    char command, c;

    cursor = tail;
    while(M--){
        cin >> command;
        if(command == 'L') left();
        else if(command == 'D') right();
        else if(command == 'B') delete_char();
        else if(command == 'P') {
            cin >> c;
            add_char(c);
        }
    }
    output();
}