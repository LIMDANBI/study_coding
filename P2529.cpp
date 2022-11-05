#include<iostream>
#include<vector>
#include<string>
using namespace std;

int k;
long long min_val = 10000000001;
long long max_val = 0;

string min_str = "", max_str = "";

bool isuse[10];
vector<char> v;
vector<int> num;

void input(){
    cin >> k;
    char c;
    for(int i=0; i<k; i++){
        cin >> c; 
        v.push_back(c);
    }
}

void backtracking(int cnt){
    if(cnt == k){
        bool flag = true;
        for(int i=0; i<k; i++){
            if(v[i]=='<'){
                if(num[i] >= num[i+1]){
                    flag = false;
                    break;
                }
            }
            else{
                if(num[i] <= num[i+1]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            string str = "";
            for(int i=0; i<k+1; i++) str+=to_string(num[i]);
            long long str_to_num = stoull(str);
            if(str_to_num < min_val){
                min_val = str_to_num;
                min_str = str;
            }
            if(max_val < str_to_num){
                max_val = str_to_num;
                max_str = str;
            }
        }
        return ; 
    }
    for(int i=0; i<10; i++){
        if(isuse[i]) continue;
        isuse[i] = true;
        num.push_back(i);
        backtracking(cnt+1);
        num.pop_back();
        isuse[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    for(int i=0; i<10; i++){
        isuse[i] = true;
        num.push_back(i);
        backtracking(0);
        num.pop_back();
        isuse[i] = false;
    }
    cout << max_str << "\n" << min_str;
}