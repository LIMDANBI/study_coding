#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (1){
        string str; cin >> str;
        if(str == "end") break;

        bool isGood = true;
        bool isVowel = false;
        bool isConsonant = true;
        int cntConsonant=0, cntVowel = 0;
       
        if(str[0]=='a' || str[0]=='e' || str[0]=='i' || str[0]=='o' || str[0]=='u'){
            cntVowel = 1;
            isVowel = true;
            isConsonant = false;
        }
        else cntConsonant = 1;

        for(int i=1; i<str.size(); i++){

            // 규칙 1, 2 확인
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') { // 모음
                isVowel = true;
                if(isConsonant){
                    isConsonant = false;
                    cntVowel = 1;
                }
                else cntVowel++;
                if(cntVowel == 3){
                    isGood = false;
                    break;
                }
            }
            else{ // 자음
                if(isConsonant) cntConsonant++;
                else {
                    isConsonant = true;
                    cntConsonant = 1;
                }
                if(cntConsonant == 3){
                    isGood = false;
                    break;
                }
            }

            // 규칙 3 확인 
            if(str[i]==str[i-1]){
                if(str[i]=='o' || str[i]=='e') continue;
                else{
                    isGood = false;
                    break;
                }
            }
        }

        if(isGood && isVowel) cout << "<" << str << ">" << " is acceptable.\n";
        else cout << "<" << str << ">" << " is not acceptable.\n";
    }
    
}