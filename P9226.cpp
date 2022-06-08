#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str;
    while(1){
        cin >> str;
        if(str == "#") break;
        queue<char> q;
        for(int i=0; i<str.size(); i++) q.push(str[i]);
        for(int i=0; i<str.size(); i++) {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') break;
            else{
                char tmp = q.front();
                q.pop();
                q.push(tmp);
            }
        }
        while (!q.empty()){
            cout << q.front();
            q.pop();
        }
        cout << "ay\n";
    }
}