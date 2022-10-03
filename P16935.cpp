#include<iostream>
#define MAX 101
using namespace std;

int N, M, R;
int arr[MAX][MAX], tmp_arr[MAX][MAX];

void input(){
    cin >> N >> M >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> arr[i][j];
    }
}

void arr_copy(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) arr[i][j] = tmp_arr[i][j];
    }
}

void swap_NM(){
    int tmp = N;
    N = M;
    M = tmp;
}

void arr_oper1(){ // 상하 반전
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) tmp_arr[N-1-i][j] = arr[i][j];
    } arr_copy();
}

void arr_oper2(){ // 좌우 반전
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) tmp_arr[i][M-1-j] = arr[i][j];
    } arr_copy();
}

void arr_oper3(){ // 오른쪽으로 90도 회전
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) tmp_arr[j][N-1-i] = arr[i][j];
    }
    swap_NM();
    arr_copy();
}

void arr_oper4(){ // 왼쪽으로 90도 회전
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) tmp_arr[M-1-j][i] = arr[i][j];
    }
    swap_NM(); 
    arr_copy();
}

void arr_oper5(){ // 1번 그룹의 부분 배열을 2번 그룹 위치로, 2번을 3번으로, 3번을 4번으로, 4번을 1번으로 이동
    int rmid=N/2;
    int cmid=M/2;
    for(int i=0; i<rmid; i++){ // 1 to 2
        for(int j=cmid; j<M; j++) tmp_arr[i][j] = arr[i][j-cmid];
    }
    for(int i=rmid; i<N; i++){ // 2 to 3
        for(int j=cmid; j<M; j++) tmp_arr[i][j] = arr[i-rmid][j];
    }
    for(int i=rmid; i<N; i++){ // 3 to 4
        for(int j=0; j<cmid; j++) tmp_arr[i][j] = arr[i][cmid+j];
    }
    for(int i=0; i<rmid; i++){ // 4 to 1
        for(int j=0; j<cmid; j++) tmp_arr[i][j] = arr[rmid+i][j];
    }
    arr_copy();
}

void arr_oper6(){ // 1번 그룹의 부분 배열을 4번 그룹 위치로, 4번을 3번으로, 3번을 2번으로, 2번을 1번으로 이동
    int rmid=N/2;
    int cmid=M/2;
    for(int i=0; i<rmid; i++){ // 2 to 1
        for(int j=cmid; j<M; j++) tmp_arr[i][j-cmid] = arr[i][j];
    }
    for(int i=rmid; i<N; i++){ // 3 to 2
        for(int j=cmid; j<M; j++) tmp_arr[i-rmid][j] = arr[i][j];
    }
    for(int i=rmid; i<N; i++){ // 4 to 3
        for(int j=0; j<cmid; j++) tmp_arr[i][cmid+j] = arr[i][j];
    }
    for(int i=0; i<rmid; i++){ // 1 to 4
        for(int j=0; j<cmid; j++) tmp_arr[rmid+i][j] = arr[i][j];
    }
    arr_copy();
}

void solution(){
    int oper;
    while (R--){
        cin >> oper;
        if(oper==1) arr_oper1();
        else if(oper==2) arr_oper2();
        else if(oper==3) arr_oper3();
        else if(oper==4) arr_oper4();
        else if(oper==5) arr_oper5();
        else if(oper==6) arr_oper6();
    }
}

void output(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    output();
}