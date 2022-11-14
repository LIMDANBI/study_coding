#include<iostream>
#include<string>
using namespace std;

int ans;
string str; // 숫자판의 정보
int changeCnt; // 교환 횟수

void change(int cnt, string num){
    if(cnt == changeCnt){
        ans = max(ans, stoi(num));
        return ; 
    }
    for(int i=0; i<num.size()-1; i++){
        for(int j=i+1; j<num.size(); j++){
            string changedNum = num;
            char tmp = num[j];
            changedNum[j] = num[i];
            changedNum[i] = tmp; 
            change(cnt+1, changedNum);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        ans = 0;
        cin >> str >> changeCnt;
        if(changeCnt>str.size()) changeCnt = str.size();
        change(0, str);
        cout << "#" << t << " " << ans << "\n";
    }
}