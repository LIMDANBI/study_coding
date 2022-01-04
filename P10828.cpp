#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct{
    int cnt;
    node *top;
} stack;

void push(stack *s, int num){
    node *n = (node*)malloc(sizeof(node));
    n->data = num;
    n->next = s->top;
    s->top = n;
    s->cnt++;
}

int pop(stack *s){
    if(s->cnt==0) return -1;
    int tmp = s->top->data;
    node *n = s->top;
    s->top = n->next;
    free(n);
    s->cnt--;
    return tmp;
}

int size(stack *s){
    return s->cnt;
}

int isempty(stack *s){
    if(s->cnt==0) return 1;
    return 0;
}

int top(stack *s){
    if(s->cnt==0) return -1;
    return s->top->data;
}

int main(){
    int n; cin>>n;
    string str; int num;
    stack s; s.cnt=0; s.top=NULL;
    while (n--){
        cin>>str;
        if(str=="push"){
            cin>>num; push(&s, num);
        }
        else if(str=="pop") cout << pop(&s) << '\n';
        else if(str=="size") cout << size(&s) << '\n';
        else if(str=="empty") cout << isempty(&s) << '\n';
        else if(str=="top") cout << top(&s) << '\n';
    }
}

/* 라이브러리 이용 */

// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
    
//    int n; cin >> n;
//    stack<int> st;

//    while (n--) {
//       string s; cin >> s;
//       if (s == "push") {
//          int x; cin >> x;
//          st.push(x);
//       }
//       else if (s == "top")
//          cout << (st.empty() ? -1 : st.top()) << '\n';
//       else if (s == "size")
//          cout << st.size() << '\n';
//       else if (s == "empty")
//          cout << st.empty() << '\n';
//       else {
//          if (st.empty()) cout << -1 << '\n';
//          else {
//             cout << st.top() << '\n';
//             st.pop();
//          }
//       }
//    }
//    return 0;
// }