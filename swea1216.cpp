#include<iostream>
#define MAX 100
using namespace std;

int ans;
bool isfind;
char arr[MAX][MAX];

void input(){
    int n; cin >> n;
    for(int i=0; i<MAX; i++){
        string str; cin >> str;
        for(int j=0; j<MAX; j++) arr[i][j] = str[j];
    }

    // init
    ans=1;
    isfind = false;
}

bool isPalindrome(string str){
    int mid = str.size()/2;
    for(int i=0; i<mid; i++){
        if(str[i] != str[str.size()-1-i]) return false;
    }
    return true;
}

void findPalindrome(int L){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(i+L<=MAX){
                string str = "";
                for(int k=0; k<L; k++) str+=arr[i+k][j];
                if(isPalindrome(str)){
                    isfind = true;
                    ans = L;
                    return;
                }
            }
            if(j+L<=MAX){
                string str = "";
                for(int k=0; k<L; k++) str+=arr[i][j+k];
                if(isPalindrome(str)){
                    isfind = true;
                    ans = L;
                    return;
                }
            }
        }
    }
}

void solution(){
    for(int len=MAX; len>1 && !isfind; len--) findPalindrome(len);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        input();
        solution();
        cout << "#" << t << " " << ans << "\n"; 
    }
}