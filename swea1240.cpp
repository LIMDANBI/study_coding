#include<iostream>
using namespace std;

int N, M;
char arr[51][101];
string code[10] = {"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"};

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<M; j++) arr[i][j] = str[j];
    }
}

pair<int, int> find_last_pos(){
    for(int i=0; i<N; i++){
        for(int j=M-1; j>=55; j--){
            if(arr[i][j]=='1') return {i,j};
        }
    }
}

int solution(){
    pair<int, int> pos = find_last_pos();
    int row = pos.first;
    int col = pos.second - 55;

    string encryption = "";
    for(int i=0; i<8; i++){
        string str = "";
        for(int j=0; j<7; j++) str+=arr[row][col+i*7+j];
        for(int j=0; j<10; j++){
            if(str == code[j]){
                encryption+=to_string(j);
                break;
            }
        }
    }

    int odd=0, even=0;
    for(int i=0; i<8; i++){
        if(i%2) even+=encryption[i]-'0';
        else odd+=encryption[i]-'0';
    }

    if((odd*3+even)%10 == 0) return odd+even; // 올바른 암호코드는 (홀수 자리의 합 x 3) + (짝수 자리의 합)이 10의 배수
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}