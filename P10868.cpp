#include<iostream>
#include<vector>
#define INF 1000000001
using namespace std;

vector<int> IDT; // indexed tree (구간 최솟값을 저장)
int N, M, num, a, b, tsize=1;

void init(){ // 앞서 초기화한 leaf node 값을 가지고 internal node들을 구간 최솟값으로 채워 나감
    for(int i=tsize-1; i>0; i--)
        IDT[i] = min(IDT[i<<1], IDT[(i<<1)|1]);
}

int minQuery(int l, int r){
    l+=(tsize-1); r+=(tsize-1); // tree에 알맞는 index로 변환
    int min_value = INF;
    while (l<=r){
        if((l&1)==1) min_value = min(min_value, IDT[l]); // tree의 right일 때 값을 취함
        if((r&1)==0) min_value = min(min_value, IDT[r]); // tree의 left일 때 값을 취함

        l = (l+1)>>1; // (left+1)/2 node로 이동
        r = (r-1)>>1; // (right-1)/2 node로 이동
    }
    return min_value;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    while(tsize<N) tsize<<=1;  // tree size를 구하기 위해 N보다 크면서 N과 가장 가까운 2의 거듭제곱을 구함
    IDT.resize(tsize<<1);  // tree size 설정 
    for(int i=1; i<IDT.size(); i++) IDT[i] = INF; // minQuery시 비교를 위해 초기화
    for(int i=tsize; i<tsize+N; i++){ // tree의 leaf node들을 입력 값으로 채움
        cin >> num;
        IDT[i] = num;
    }
    init(); // IDT를 만듦
    for(int i=0; i<M; i++){
        cin >> a >> b;
        cout << minQuery(a, b) << '\n'; // [a, b]구간 최솟값 출력
    }
}