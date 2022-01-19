#include<iostream>
#include<vector>
#define INF 1000000001
using namespace std;

int N, M, n, a, b, tree_size=1;
vector<int> min_tree, max_tree; // 구간 최솟값, 최대값을 저장할 vector

void init(){
    for(int i=tree_size-1; i>0; i--){ // 앞서 초기화한 leaf node 값을 가지고 internal node들을 구간 최소, 최대로 채워 나감
        min_tree[i] = min(min_tree[i<<1], min_tree[(i<<1)|1]); // i<<1 (=i*2) , (i<<1)|1 (=i*2+1)
        max_tree[i] = max(max_tree[i<<1], max_tree[(i<<1)|1]);
    }
}

int minQuery(int left, int right){
    left+=(tree_size-1); right+=(tree_size-1); // tree에 알맞는 index로 변환
    int min_value = INF; 
    while (left<=right){ // O(log N)
        if((left&1)==1) min_value = min(min_value, min_tree[left]); // tree의 right일 때 값을 취함
        if((right&1)==0) min_value = min(min_value, min_tree[right]); // tree의 left일 때 값을 취함

        left = (left+1)>>1; // (left+1)/2 node로 이동
        right = (right-1)>>1; // (right-1)/2 node로 이동
    }
    return min_value;
}

int maxQuery(int left, int right){ // minQuery와 유사 (min과 max의 차이)
    left+=(tree_size-1); right+=(tree_size-1);
    int max_value = 0;
    while (left<=right){
        if((left&1)==1) max_value = max(max_value, max_tree[left]);
        if((right&1)==0) max_value = max(max_value, max_tree[right]);

        left = (left+1)>>1;
        right = (right-1)>>1;
    }
    return max_value;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    while (tree_size < N) tree_size<<=1; // tree size를 구하기 위해 N보다 크면서 N과 가장 가까운 2의 거듭제곱을 구함.
    min_tree.resize(tree_size<<1); // tree size 설정 
    max_tree.resize(tree_size<<1); // tree size 설정 
    for(int i=1; i<min_tree.size(); i++) min_tree[i] = INF;  // minQuery시 비교를 위해 초기화 (max_tree는 초기화하지 않아도 0으로 되어 있음)
    for(int i=tree_size; i<tree_size+N; i++){ // tree의 leaf node들을 입력 값으로 채움
        cin>>n;
        min_tree[i] = n;
        max_tree[i] = n;
    }
    init(); // min_tree, max_tree를 만듦
    for(int i=0; i<M; i++){
        cin>>a>>b;
        cout << minQuery(a, b) << ' ' << maxQuery(a, b) << '\n'; // 구간 최소, 최대 출력
    }
}