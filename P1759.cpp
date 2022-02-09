#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int L, C;
vector<char> character;
vector<char> password;

bool promising(){ // 유망한진 판단
    int aeiou = 0;
    for(int i=0; i<L; i++){ // 모음의 개수 체크
        if(password[i]=='a' || password[i]=='e' || password[i] =='i' || password[i] == 'o' || password[i] == 'u') aeiou++;
    }
    if(aeiou>=1 && L-aeiou>=2) return true; // 자음 = L - 모음
    return false;
}

void make(int idx){
    if(password.size()==L){ // 길이를 만족한 경우
        if(promising()){ // 조건을 만족하는지 체크
            for(int i=0; i<L; i++) cout << password[i]; // 길이+조건이 만족하는 경우 password 출력
            cout << '\n';
        }
    }
    for(int i=idx; i<C; i++){
        password.push_back(character[i]); // 현재 글자 정하기
        make(i+1); // 다음 글자 정하기
        password.pop_back(); // 빼주고 다른 글자 넣어보기!
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    char tmp; cin >> L >> C; // 암호를 이루는 서로 다른 알파벳 수 , 암호에 사용했을 법한 문자들
    for(int i=0; i<C; i++) {
        cin >> tmp;
        character.push_back(tmp);
    }
    sort(character.begin(), character.end()); // 사전 순 정렬
    make(0); // 암호 만들기
}