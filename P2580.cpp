#include<iostream>
using namespace std;

int map[9][9];

void input(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
            cin >> map[i][j];
    }
}

void output(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) 
            cout << map[i][j] << " ";
        cout << "\n";
    }
}

bool promising(int r, int c, int num){
    for(int i=0; i<9; i++){ // check row, col
        if(map[r][i]==num) return false;
        if(map[i][c]==num) return false;
    }
    for(int i=(r/3)*3; i<(r/3)*3+3; i++){ // check small map
        for(int j=(c/3)*3; j<(c/3)*3+3; j++){
            if(map[i][j]==num) return false;
        }
    }
    return true;
}

void sudoku(int r, int c){
    if(r==9){
        output();
        exit(0);
    }
    if(c==9) sudoku(r+1, 0);
    else if(map[r][c]==0){
        for(int num=1; num<10; num++){ // backtracking
            if(promising(r, c, num)){
                map[r][c] = num;
                sudoku(r, c+1);
                map[r][c] = 0;
            }
        }
    }
    else sudoku(r, c+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    sudoku(0, 0);
}