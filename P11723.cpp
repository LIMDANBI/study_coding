#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int M; cin >> M;
    string oper;
    int num, SET=0;
    while (M--){
        cin >> oper;
        if(oper=="all") SET = (1<<21)-1;
        else if(oper=="empty") SET = 0;
        else{
            cin >> num;
            if(oper=="add") SET|=(1<<num);
            else if(oper=="remove") SET&=~(1<<num);
            else if(oper=="check") {
                if(SET&(1<<num)) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
            else if(oper=="toggle") SET^=(1<<num);
        }
    }
}