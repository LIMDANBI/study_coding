#include<iostream>
#include<vector>
#define MAX 12
#define INF 1000000000
using namespace std;

vector<int> v;
int num[MAX], oper[4];
int N, min_res=INF, max_res=-INF;

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> num[i];
    for(int i=0; i<4; i++) cin >> oper[i];
}

void solution(){
    if(v.size()==N-1){
        int idx = 1;
        int res = num[0];
        for(int i=0; i<(int)v.size(); i++){
            if(v[i]==0) res+=num[idx];
            else if(v[i]==1) res-=num[idx];
            else if(v[i]==2) res*=num[idx];
            else if(v[i]==3) res/=num[idx];
            idx++;
        }
        min_res = min(res, min_res);
        max_res = max(res, max_res);
        return ; 
    }
    for(int i=0; i<4; i++){
        if(!oper[i]) continue;
        v.push_back(i); oper[i]--;
        solution();
        v.pop_back(); oper[i]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    cout << max_res << "\n" << min_res;
}