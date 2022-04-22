#include <iostream>
#define MAX 300
using namespace std;

int N, M, R;
int arr[MAX][MAX];

void rotate(){
    int cnt = min(N, M)/2; // 돌려야 할 사각형의 개수
    for(int c=0; c<cnt; c++){
        int maxN = N-c-1;
        int maxM = M-c-1;
        int tmp = arr[c][c];
        for(int j=c; j<maxM; j++) arr[c][j] = arr[c][j+1]; // 상
        for(int i=c; i<maxN; i++) arr[i][maxM] = arr[i+1][maxM]; // 우
        for(int j=maxM; j>c; j--) arr[maxN][j] = arr[maxN][j-1]; // 하
        for(int i=maxN; i>c; i--) arr[i][c] = arr[i-1][c]; // 좌
        arr[c+1][c] = tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> arr[i][j];
    }
    while (R--) rotate(); // 주어진 배열을 R번 회전
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cout << arr[i][j] << " ";
        cout << "\n";
    }
}