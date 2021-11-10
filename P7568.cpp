#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int, int>> build;
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        build.push_back(make_pair(x, y));
    }
    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n; j++){
            if(i!=j){
                if(build[i].first < build[j].first && build[i].second < build[j].second)
                    cnt++;
            }
        }
        cout << cnt << ' ';
    }
}