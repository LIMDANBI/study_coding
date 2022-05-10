#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
        string str;
        int lower=0, upper=0, number=0, empty=0; // 소문자, 대문자, 숫자, 공백
        getline(cin, str);
        if(str=="") break;
        for(int i=0; i<str.length(); i++){
            if('a'<=str[i] && str[i]<='z') lower++;
            if('A'<=str[i] && str[i]<='Z') upper++;
            if('0'<=str[i] && str[i]<='9') number++;
            if(str[i]==' ') empty++;
        }
        cout << lower << " " << upper << " " << number << " " << empty << "\n";
    }
}