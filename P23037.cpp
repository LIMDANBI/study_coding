#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0, arr[10]={0,};
    string str; cin >> str;
    for(int i=1; i<10; i++){
        arr[i] = 1;
        for(int j=0; j<5; j++) arr[i]*=i;
    }
    for(int i=0; i<str.length(); i++) ans += arr[str[i]-'0'];
    cout << ans;
}