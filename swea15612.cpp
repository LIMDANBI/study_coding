#include<iostream>
#define SIZE 8
using namespace std;

string map[SIZE];

void input(){
    for(int i=0; i<SIZE; i++) cin >> map[i];
}

bool isyes(){
    for(int row=0; row<SIZE; row++){ // 행 check
        bool check = false;
        for(int col=0; col<SIZE; col++){
            if(map[row][col]=='O'){
                if(check) return false;
                check = true;
            }
        }
        if(!check) return false; // 정확히 8개의 룩이 있어야 함
    }

    for(int col=0; col<SIZE; col++){ // 열 check
        bool check = false;
        for(int row=0; row<SIZE; row++){
            if(map[row][col]=='O'){
                if(check) return false;
                check = true;
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        input();
        if(isyes()) cout << "#" << t << " yes\n";
        else cout << "#" << t << " no\n";
    }
}