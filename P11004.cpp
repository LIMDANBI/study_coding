#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(long a, long b){
    if(a<b)return true; else return false;
}
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    vector<long> num; 
    int n, k; long a; cin>>n>>k;
    while (n--){
        cin>>a; num.push_back(a);
    } sort(num.begin(), num.end(), compare); cout<<num[k-1];
}