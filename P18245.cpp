#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1; true; i++){
        string str; getline(cin, str);
        if(str == "Was it a cat I saw?") return 0;
        int idx=0;
        while (idx<str.length()){
            cout << str[idx];
            idx+=(i+1);
        } cout << "\n";
    }
}