#include<iostream>
#define MAX 8
using namespace std;

int L; // 찾아야 하는 회문의 길이
char arr[MAX][MAX];

void input(){
    cin >> L;
    for(int i=0; i<MAX; i++){
        string line; cin >> line;
        for(int j=0; j<MAX; j++) arr[i][j] = line[j];
    }
}

bool isPalindrome(string str){
    int mid = (str.size()+1)/2-1;
    for(int i=0; i<=mid; i++){
        if(str[i]!=str[str.size()-1-i]) return false;
    }
    return true;
}

int solution(){
    int res = 0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            
            if(i+L<=MAX){
                string str = ""; // 세로 직선
                for(int k=0; k<L; k++) str+=arr[i+k][j];
                if(isPalindrome(str)) res++;
            }
            if(j+L<=MAX){
                string str = ""; // 가로 직선
                for(int k=0; k<L; k++) str+=arr[i][j+k];
                if(isPalindrome(str)) res++;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}