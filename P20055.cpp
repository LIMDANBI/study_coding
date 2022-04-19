#include<iostream>
#include<vector>
#define MAX 202
using namespace std;

int N, K, ans=1;
int A[MAX]; // i번 칸의 내구도는 Ai
bool isrobot[MAX];
vector<int> robot;

bool move(){
    
    // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전
    // 벨트 회전
    int tmpA = A[2*N];
    bool tmpR = isrobot[2*N];
    for(int i=2*N; i>1; i--){
        A[i] = A[i-1];
        isrobot[i] = isrobot[i-1];
        if(i==N && isrobot[i]){ // 로봇이 내리는 위치에 도달하면 그 즉시 내림
            isrobot[i] = false;
            for(int r=0; r<robot.size(); r++){
                if(robot[r]+1==i) {
                    robot.erase(robot.begin()+r);
                    break;
                }
            }
        }
    }
    A[1] = tmpA;
    isrobot[1] = tmpR;
    
    // 로봇 회전
    for(int i=0; i<robot.size(); i++){
        if(robot[i]==2*N) robot[i]=0;
        else robot[i]++;
    }

    // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면(내구도가 1 이상 남아 있는 경우) 이동
    for(int i=0; i<robot.size(); i++){
        if(robot[i]==2*N){
            if(A[0]>0 && !isrobot[0]){
                robot[i] = 0;
                isrobot[0] = true;
                isrobot[i] = false;
                A[0]--;  // 로봇 이동, 내구도는 즉시 1만큼 감소
            }
        }
        else{
            if(A[i+1]>0 && !isrobot[i+1]){
                robot[i]++;
                isrobot[i+1] = true;
                isrobot[i] = false;
                A[i+1]--;  // 로봇 이동, 내구도는 즉시 1만큼 감소
            }
        }
    }

    // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올림
    if(A[0]>0) {
        isrobot[0] = true;
        robot.push_back(0);
        A[0]--; // 로봇 올림, 내구도는 즉시 1만큼 감소
    }

    // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료
    int durability=0;
    for(int i=1; i<=2*N; i++){
        if(A[i]==0) durability++;
    }
    if(K<=durability) return false;
    else return true;
    // return K>durability;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=2*N; i++) cin >> A[i];
    while(move()) ans++;
    cout << ans;
}