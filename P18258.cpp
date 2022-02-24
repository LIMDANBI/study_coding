# include <iostream>
# include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    queue<int> q;
    while(n--){
        string S; cin >> S;
        if(S == "push"){
            int x; cin >> x;
            q.push(x);
        }
        else if(S == "pop"){
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(S == "size"){
            cout << q.size() <<'\n';
        }
        else if(S == "empty"){
            cout << q.empty() << '\n';
        }
        else if (S == "front") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (S == "back") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
}