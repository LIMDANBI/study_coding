#include<iostream>
#define MAX 100
using namespace std;

int max_sum = 0;
int arr[MAX][MAX];

void input(){
    int tmp; cin >> tmp;
    for(int i=0; i<MAX; i++){
        int sum = 0;
        for(int j=0; j<MAX; j++){
            cin >> arr[i][j];
            sum+=arr[i][j];
        }
        max_sum = max(max_sum, sum); // row
    }
}

void solution(){

    int sum;
    for(int j=0; j<MAX; j++){
        sum = 0;
        for(int i=0; i<MAX; i++) sum+=arr[i][j];
       max_sum = max(max_sum, sum); // col
    }

    sum = 0;
    for(int i=0; i<MAX; i++) sum+=arr[i][i]; // diagonal 1
    max_sum = max(max_sum, sum);

    sum = 0;
    for(int i=0; i<MAX; i++) sum+=arr[i][MAX-i-1]; // diagonal 2
    max_sum = max(max_sum, sum);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        max_sum = 0;
        input();
        solution();
        cout << "#" << t << " " << max_sum << "\n";
    }
}