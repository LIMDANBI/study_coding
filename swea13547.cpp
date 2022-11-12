#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    
    string str;
    for(int t=1; t<=T; t++){
    	cin >> str;
        int size= str.size(), win = 0;
        for(int i=0; i<size; i++){
            if(str[i] == 'o') win++;
        }
        if(win + (15-size) >= 8 ) cout << "#" << t << " YES\n";
        else cout << "#" << t << " NO\n";
    }
}