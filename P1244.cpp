#include <iostream>
#define MAX 101
using namespace std;

bool S[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    // 1. input
    int snum; cin >> snum;
    for(int i=1; i<=snum; i++) cin >> S[i];
    
    // 2. solution
    int student, sex, num; cin >> student;
    while(student--){
        cin >> sex >> num;
        if(sex==1){ // man
            int cnt = 1;
            while(num*cnt <= snum){
                S[num*cnt] = !S[num*cnt];
                cnt++;
            }
        }
        else{ // woman
            int cnt = 0;
            while(1){
                if(num-cnt<1 || num+cnt>snum) break; // out of range
                if(S[num-cnt]!=S[num+cnt]) break;
                cnt++;
            }
            for(int i=num-cnt+1; i<num+cnt; i++) S[i] = !S[i];
        }
    }

    // 3. output
    for(int i=1; i<=snum; i++) {
        cout << S[i] << " ";
        if(i%20==0) cout << "\n";
    }
}