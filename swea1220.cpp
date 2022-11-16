#include<iostream>
#define MAX 100
#define N 1
#define S 2
using namespace std;

int len;
int arr[MAX][MAX];

void input(){
    cin >> len; // 정사각형 테이블의 한 변의 길이 (항상 100)
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++) cin >> arr[i][j];
    }
}

int solution(){
    int res = 0;
    for(int col=0; col<MAX; col++){
        bool findN = false;
        for(int row=0; row<MAX; row++){
            if(findN){
                if(arr[row][col] == S){
                    findN = false;
                    res++;
                }
            }
            else{
                if(arr[row][col] == N) findN = true;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}