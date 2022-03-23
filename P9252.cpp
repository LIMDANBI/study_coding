#include<iostream>
#define MAX 1001
using namespace std;

string s1, s2;
int dp[MAX][MAX];

void solution(){ 
    int i, j;
    for(i=0; i<s1.length(); i++){ // DP를 통해 LCS 길이를 구함
        for(j=0; j<s2.length(); j++){
            if(s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    } 
    int lenLcs = dp[i][j];
    
    string lcs="";
    while (1){ // LCS를 구함
        if(dp[i][j] == dp[i-1][j-1]) { i--; j--;}
        else if(dp[i][j] == dp[i-1][j]) i--;
        else if(dp[i][j] == dp[i][j-1]) j--;
        else {
            lcs+=s1[i-1];
            i--; j--;
        }
        if(lcs.length()==lenLcs) break;
    }    
    cout << lenLcs << '\n';
    for(i = lcs.length()-1; i>=0; i--) cout << lcs[i];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    solution();
}