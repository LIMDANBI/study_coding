#include<iostream>
#include<queue>
#define MAX 8
using namespace std;

queue<int> q;

void input(){
    int n; cin >> n;
    for(int i=0; i<MAX; i++){
        cin >> n; q.push(n);
    }
}

void solution(){
    bool flag = true;
    while(flag){
        for(int i=1; i<=5; i++){
            if(q.front()-i <= 0){
                q.pop();
                q.push(0);
                flag = false;
                break;
            }
            else{
                int tmp = q.front() - i;
                q.pop();
                q.push(tmp);
            }
        }
    }
}

void output(int t){
    cout << "#" << t << " ";
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        input();
        solution();
        output(t);
    }
}