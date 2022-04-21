#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<set>
using namespace std;

string str;
int T, N, K, pow16[7]; // N: 숫자 개수, K: 크기 순서

bool compare (long long a, long long b) { return a>b; }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    pow16[0] = 1; for(int i=1; i<7; i++) pow16[i] = pow16[i-1]*16;
    cin >> T;
    for(int t=1; t<=T; t++){
        set<int> password_set;
        vector<long long> password;
        cin >> N >> K >> str;
        deque<int> num; // 보물 상자에 적힌 숫자들
        long long pwd=0; // 비밀번호
        int roatate_num = N/4; // 회전 횟수, pwd 위치
        for(int i=0; i<str.size(); i++){ // character to number
            if(str[i]<58) num.push_back(str[i]-48); // 1~9
            else num.push_back(str[i]-55); // A(10)~F(15)
        }
        for(int r=0; r<roatate_num; r++){ // rotateNum번째 회전은 0회전과 동일
            if(r>0){ // 시계 방향으로 한칸 이동 (첫번 째 turn은 pass)
                int tmp = num.back(); num.pop_back();
                num.push_front(tmp);
            }
            for(int n=0; n<num.size(); n++){  // 가능한 pwd를 만들어서 중복 없이 저장
                int idx = roatate_num - n%roatate_num - 1;
                if((n+1)%roatate_num==0){ // 하나의 pwd 완성
                    pwd+=num[n];
                    if(password_set.count(pwd)==0) {
                        password.push_back(pwd);
                        password_set.insert(pwd);
                    }
                    pwd=0; // 새로운 pwd를 만들기 위해 초기화
                }
                else pwd+=(num[n]*pow16[idx]);
            }
        }
        sort(password.begin(), password.end(), compare); // 정렬 
        cout << "#" << t << " " << password[K-1] << "\n"; // K번째로 큰 pwd 출력
    }
}