#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;

int N, M, K, num, a, b, c, tsize=1;
vector<long long> IDT;

void init(){ // 앞서 초기화한 leaf node 값을 가지고 internal node들을 '구간곱 % MOD'로 채워 나감
    for(int i=tsize-1; i>0; i--)
        IDT[i] = (IDT[i<<1]*IDT[(i<<1)|1])%MOD;
}

void update(int idx, int val){
    idx+=(tsize-1); // tree에 알맞는 index로 변환
    IDT[idx] = val; // b번째 값을 c로 update
    while ((idx>>=1)>0){ // 조상들도 update
        IDT[idx] = (IDT[idx<<1]*IDT[(idx<<1)|1])%MOD;
    } 
}

long long section_mul(int left, int right){
    left+=(tsize-1); right+=(tsize-1); // tree에 알맞는 index로 변환
    long long ans = 1;
    while (left<=right){ // 구간 곱을 구함
        if((left&1)==1) ans = (ans*IDT[left])%MOD; // tree의 right일 때 값을 취함
        if((right&1)==0) ans = (ans*IDT[right])%MOD; // tree의 left일 때 값을 취함
        left = (left+1)>>1; // (left+1)/2 node로 이동
        right = (right-1)>>1; // (right-1)/2 node로 이동
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    while (tsize<N) tsize<<=1; // tree size를 구하기 위해 N보다 크면서 N과 가장 가까운 2의 거듭제곱을 구함
    IDT.resize(tsize<<1);  // tree size 설정
    for(int i=1; i<=IDT.size(); i++) IDT[i]=1; // 곱셈을 위해 IDT의 모든 값을 1로 초기화
    for(int i=tsize; i<tsize+N; i++){ // tree의 leaf node들을 입력 값으로 채움
        cin>>num;
        IDT[i] = num;
    }
    init(); // IDT를 만듦
    for(int i=0; i<M+K; i++){
        cin >> a >> b >> c;
        if(a==1) update(b, c); // b번째 값을 c로 바꿈
        else if(a==2) cout << section_mul(b, c) << '\n'; // [b, c] 구간곱 출력
    }
}