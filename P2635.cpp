#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;

void rule(int a, int b){

    vector<int> v;
    v.push_back(a);
    v.push_back(b);

    while(1){
        if(a-b<0) break;
        v.push_back(a-b);
        int tmp = b;
        b = a-b;
        a = tmp;
    }

    if(ans.size() < v.size()) ans = v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int num; cin >> num;

    for(int i=1; i<=num; i++) rule(num, i);
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
}