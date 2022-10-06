#include<iostream>
#define MAX 201
using namespace std;

int n, k;
int arr[MAX];
bool isperson[MAX];

void input(){
    cin >> n >> k;
    for(int i=0; i<2*n; i++) cin >> arr[i];
}

void print_map(){
    for(int i=0; i<2*n; i++) cout << arr[i] << " ";
    cout << "\n";
}

bool isContinue(){ // 안정성이 0인 칸이 k개 이상이라면 과정을 종료
    int cnt = 0;
    for(int i=0; i<2*n; i++){
        if(arr[i]==0) cnt++;
    }
    if(cnt<k) return true;
    return false;
}

void rotate(){ // 무빙워크가 한 칸 회전 (사람도 같이 회전 - 사람은 n-1 칸에서 내림)
    int tmp = arr[2*n-1];
    for(int i=2*n-1; i>0; i--) {
        arr[i] = arr[i-1];
        if(i<n-1) isperson[i] = isperson[i-1];
    }
    isperson[0] = false;
    arr[0] = tmp;
}

void move_person(){ // 가장 먼저 무빙워크에 올라간 사람부터 무빙워크가 회전하는 방향으로 한 칸 이동할 수 있으면 이동
    for(int i=n-2; i>0; i--){
        if(isperson[i] && arr[i+1]>0 && !isperson[i+1]){ // 해당 칸에 사람이 있고 이동할 수 있는 경우 
            isperson[i+1] = true;
            isperson[i] = false;
            arr[i+1]--;
            if(i+1==n-1) isperson[i+1] = false;
        }
    }
}

void add_person(){ // 1번 칸에 사람이 없고 안정성이 0이 아니라면 사람을 한 명 더 올림 
    if(arr[0]>0 && !isperson[0]){
        isperson[0] = true;
        arr[0]--; // 안전성 감소
    }
}

void solution(){
    int ans = 0;
    while(isContinue()){
        rotate();
        move_person();
        add_person();
        ans++;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();   
}