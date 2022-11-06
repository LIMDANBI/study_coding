#include<iostream>
#include<vector>
#include<string>
using namespace std;

int k;
string min_str = "", max_str = "";
long long min_num = 10000000001, max_num = 0;

bool isuse[10];
vector<char> v;

bool compare(int a, int b, char c){
    if(c == '<') return a < b;
    return a > b;
}

void input(){
    cin >> k;
    char c;
    for(int i=0; i<k; i++){
        cin >> c; 
        v.push_back(c);
    }
}

void backtracking(int cnt, string res){
    if(cnt == k+1){
        long long lnum = stol(res);
        if(lnum < min_num){
            min_num = lnum;
            min_str = res;
        }
        if(max_num < lnum){
            max_num = lnum;
            max_str = res;
        }
        return ; 
    }
    for(int i=0; i<10; i++){
        if(isuse[i]) continue;
        if(cnt == 0){
            isuse[i] = true;
            backtracking(cnt+1, res+to_string(i));
            isuse[i] = false;
        }
        else{
            int before = res[cnt-1] - '0';
            if(compare(before, i, v[cnt-1])){
                isuse[i] = true;
                backtracking(cnt+1, res+to_string(i));
                isuse[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    backtracking(0, "");
    cout << max_str << "\n" << min_str;
}