#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, K, tmp; 
    cin >> N >> K;
    queue<int> q;
    cout << "<";
    for(int i=1; i<=N; i++) q.push(i); // queue에 1~N 까지 집어 넣음
    while (q.size()-1){ // queue에 한명만 남을 때까지 반복
        for(int i=0; i<K-1; i++){ // K번째가 되기 전까지는 queue에 넣고 빼는 작업을 반복
            tmp = q.front();
            q.push(tmp);
            q.pop();
        }
        cout << q.front() << ", "; // K번째 사람 출력
        q.pop(); // 제거
    }
    cout << q.front() << ">"; // 마지막 사람 출력
}