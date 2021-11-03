#include <iostream>
#include <vector>
using namespace std;

vector<int> height[11];
int tree[1025] = {0, };

void dfs(int begin, int end, int level){
    int mid = (begin+end)/2;
    height[level].push_back(tree[mid]);

    if(begin == end) return;
    
    dfs(begin, mid-1, level+1);
    dfs(mid+1, end, level+1); 

}

int main(){
    int k, cnt=1, node; cin>>k;
    for(int i=0; i<k; i++) cnt*=2;
    for(int i=0; i<cnt-1; i++){
        cin>>node; tree[i]=node;
    }

    dfs(0, cnt-2, 1);

    for(int i=1; i<k+1; i++){
        for(int j=0; j<height[i].size(); j++){
            cout << height[i][j] << ' ';
        } cout << '\n';
    }
}