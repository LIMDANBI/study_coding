#include<iostream>
#include<string>
using namespace std;

int main(){
    string n;
    while (1){
        cin >> n;
        if(n=="0") break;

        int ans;
        while(1){
            ans = 0;
            for(int i=0; i<n.size(); i++){
                ans+=n[i]-'0';
            }
            if(ans<10) break;
            n = to_string(ans);
        }
        cout << ans << "\n";
    }
}