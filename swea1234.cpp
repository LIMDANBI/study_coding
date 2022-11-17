#include<iostream>
#include<vector>
using namespace std;

int L;
string pwd;

string getPwd(){
    string ans = "";
    
    vector<char> v;
    for(int i=0; i<L; i++){
        if(v.size()==0) v.push_back(pwd[i]);
        else if(v[v.size()-1] == pwd[i]) v.pop_back();
        else v.push_back(pwd[i]);
    }

    for(int i=0; i<v.size(); i++) ans+=v[i];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        cin >> L >> pwd;
        cout << "#" << t << " " << getPwd() << "\n";
    }
}