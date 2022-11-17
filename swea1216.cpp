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

void findPalindrome(int L){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(i+L<=MAX){
                bool flag = true;
                int mid = L/2;
                for(int k=0; k<=mid; k++){
                    if(arr[i+k][j] != arr[i+L-1-k][j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    isfind = true;
                    ans = L;
                    return;
                }
            }
            if(j+L<=MAX){
                bool flag = true;
                int mid = L/2;
                for(int k=0; k<=mid; k++){
                    if(arr[i][j+k] != arr[i][j+L-1-k]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
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