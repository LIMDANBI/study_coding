#include<iostream>
#include<vector>
using namespace std;

int n, m, k; 
vector<long long> arr; // 0부터 시작
vector<long long> tree; // 1부터 시작

long long init(int start, int end, int node){
    if(start==end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

long long sum(int start, int end, long long left, long long right, int node){
    if(left>end||right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, left, right, node*2) + sum(mid+1, end, left, right, node*2+1);
}

void update(int start, int end, int node, int idx, long long diff){
    if(idx<start||idx>end) return ;
    tree[node]+=diff;
    if(start!=end){
        int mid = (start+end)/2;
        update(start, mid, node*2, idx, diff);
        update(mid+1, end, node*2+1, idx, diff);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        int tmp; cin>> tmp;
        arr.push_back(tmp);
    }
    int tree_size = 1;
    while (tree_size<n) tree_size<<=1; // tree_size*=2;
    tree_size<<=1; tree.resize(tree_size);
    init(0, n-1, 1);

    for(int i=0; i<m+k; i++){
        long long a, b, c; cin>>a>>b>>c;
        if(a==1){
            update(0, n-1, 1, b-1, c-arr[b-1]);
            arr[b-1]=c;
        }
        else if(a==2) cout << sum(0, n-1, b-1, c-1, 1) << '\n';
    }
}