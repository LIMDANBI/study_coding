#include<iostream>
#include<algorithm> // reverse
#include<string>
using namespace std;

int N, M;
string C[101][101];

string bigNumAdd(string n1, string n2){
    int sum=0;
    string result;
    while (!n1.empty() || !n2.empty() || sum){ // 1의 자리부터 더함
        if(!n1.empty()){
            sum+=n1.back()-'0'; // char -> int
            n1.pop_back();
        }
        if(!n2.empty()){
            sum+=n2.back()-'0'; // char -> int
            n2.pop_back();
        }
        result.push_back((sum%10)+'0'); // int -> char
        sum/=10; // 올림수가 있는 경우 
    }
    reverse(result.begin(), result.end()); // 역순이므로 다시 원래 순서로 변환
    return result;
}

string combi(int n, int m){
    if(n==m || m==0) return "1";
    string &ans = C[n][m];
    if(ans!="") return ans; // memorization
    ans = bigNumAdd(combi(n-1, m), combi(n-1, m-1)); // 파스칼 삼각형
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    cout << combi(N, M);
}