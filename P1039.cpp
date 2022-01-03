#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int k;
queue<string> q;

void swap(string &str, int left, int right){
    char tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string str, ans = "0"; 
    cin >> str >> k;
    q.push(str);

    for(int i=0; i<k; i++){
        set<string> s;
        int q_size = q.size();
        for(int j=0; j<q_size; j++){
            string item = q.front(); q.pop();
            if(s.count(item)==1) continue;
            s.insert(item);
            for(int l=0; l<item.size()-1; l++){
                for(int r=l+1; r<item.size(); r++){
                    if(l==0 && item[r]=='0') continue;
                    swap(item, l, r);
                    q.push(item);
                    swap(item, l, r);
                }
            }
        }
    }
    while (!q.empty()){
        ans = max(ans, q.front());
        q.pop();
    }
    if(ans[0]=='0') cout << -1;
    else cout << ans;   
}