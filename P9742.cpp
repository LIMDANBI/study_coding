#include <iostream>
#include <algorithm>
using namespace std;

int num;
string str;
int fact[11] = {1,};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1; i<=10; i++) fact[i] = fact[i-1]*i;
    while (cin >> str >> num){
        cout << str << " " << num << " = ";
        if(num > fact[str.length()]){ // 해당하는 순열이 없는 경우
            cout << "No permutation\n";
            continue;
        }

        int idx=0;
        do {
            idx++;
            if(idx == num){
                cout << str << "\n";
                break;
            }
        } while (next_permutation(str.begin(), str.end()));
    }
}