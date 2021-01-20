#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >>n; string tmp;
    vector<pair<int, string>> word;
    for(int i=0; i<n; i++){
        cin >> tmp; word.push_back(make_pair(tmp.size(), tmp));
    }
    sort(word.begin(), word.end());
    cout << word[0].second <<'\n';
    for(int i=1; i<n; i++){
        if(word[i].second != word[i-1].second) cout << word[i].second <<'\n';
    }
}