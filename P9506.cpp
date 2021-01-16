#include <iostream>
using namespace std;

int main(){
    int n;
    while (1){
        cin >> n; 
        int sum=1; string ans = to_string(n)+" = 1 + ";
        if(n==-1) break;
        else{
            for(int i=2; i<n; i++){
                if(n%i==0) {
                    sum+=i;
                    if(sum == n) ans = ans + to_string(i);
                    else ans = ans + to_string(i) + " + ";
                }
            }
            if(sum == n) cout << ans << endl;
            else cout << to_string(n)+ " is NOT perfect." << endl;
        }
    }
}