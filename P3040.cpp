#include <iostream>
using namespace std;

int dwarf[9];
bool check[9];
int sum=-100;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<9; i++) {
        cin >> dwarf[i];
        sum+=dwarf[i];
    }
    for(int a=0; a<8; a++){
        for(int b=a+1; b<9; b++){
            if(dwarf[a]+dwarf[b]==sum){
                check[a] = true;
                check[b] = true;
                for(int i=0; i<9; i++){
                    if(!check[i]) cout << dwarf[i] << "\n";
                }
                return 0;
            }
        }
    }
}