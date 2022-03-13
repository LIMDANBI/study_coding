#include<iostream>
#define MAX 1001
using namespace std;

int dp[MAX][MAX], i, j;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str1, str2; cin >> str1 >> str2;
    for(i=0; i<str1.length(); i++){ // dp를 통해 LCS를 구함
        for(j=0; j<str2.length(); j++)
            if(str1[i] == str2[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
    } cout << dp[i][j];
}