#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string A, B; cin >> A >> B;
    int ans=0;
    int lenA=A.length(), lenB=B.length();
    if(lenA == lenB){ // 두 문자열의 길이가 같은 경우 
        for(int i=0; i<lenA; i++){
            if(A[i]!=B[i]) ans++;
        }
    }
    else{ // 두 문자열의 길이가 다른 경우
        if(lenA<lenB) { // A가 B보다 긺을 보장
            swap(A, B);
            swap(lenA, lenB);
        }
        int max_match=0;
        for(int i=0; i<=lenA-lenB; i++){
            int cnt = 0;
            for(int j=0; j<lenB; j++){
                if(A[i+j]==B[j]) cnt++;
            }
            max_match = max(cnt, max_match);
        }
        ans = lenB-max_match;
    }
    cout << ans;
}