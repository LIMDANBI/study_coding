#include<iostream>
#define MAX 402
using namespace std;

int n, t;
int conveyor[MAX]; // 1 2 3 6 5 1 -> (1초후) 1 1 2 3 6 5

void input(){
    cin >> n >> t;
    for(int i=0; i<2*n; i++) cin >> conveyor[i];
}

void move(){
    int tmp = conveyor[2*n-1];
    for(int i=2*n-1; i>0; i--) conveyor[i] = conveyor[i-1];
    conveyor[0] = tmp;
}

void ans(){
    for(int i=0; i<2*n; i++){
        if(i!=0 && i%n==0) cout << "\n";
        cout << conveyor[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    while(t--) move();
    ans();
}