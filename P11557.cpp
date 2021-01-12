#include <iostream>
using namespace std;

int main() {
    int T, N; cin >> T;
    string ans[T+1];
    for(int i=0; i<T; i++){
        cin >> N;
        string S[20]; int L[20]; 
        for(int j=0; j<N; j++){
            cin >> S[j] >> L[j];
        }
        int max=L[0], maxindex=0;
        for(int j=1; j<N; j++){
            if(max<L[j]){
                max=L[j]; maxindex=j;
            }
        }
        ans[i] = S[maxindex];
    }
    for(int i=0; i<T; i++) cout << ans[i] << "\n";
}