#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int ans;
string str; // 숫자판의 정보
int changeCnt; // 교환 횟수

void change(int cnt, int idx){
    if(cnt == changeCnt){
        ans = max(ans, stoi(str));
        return ; 
    }
    for(int i=idx; i<str.size()-1; i++){
        for(int j=i+1; j<str.size(); j++){
            swap(str[i], str[j]);
            change(cnt+1, i);
            swap(str[j], str[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        ans = 0;
        cin >> str >> changeCnt;
        changeCnt = min(changeCnt, (int)str.size()); // 필요없는 중복 교환 제거
        change(0, 0);
        cout << "#" << t << " " << ans << "\n";
    }
}