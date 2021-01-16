#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string alphabet; cin >> alphabet;
    int sec=0;
    for(int i=0; i<alphabet.size(); i++){
        if(alphabet.at(i) == 'A' || alphabet.at(i) == 'B' || alphabet.at(i) == 'C') sec+=3;
        else if(alphabet.at(i) == 'D' || alphabet.at(i) == 'E' || alphabet.at(i) == 'F') sec+=4;
        else if(alphabet.at(i) == 'G' || alphabet.at(i) == 'H' || alphabet.at(i) == 'I') sec+=5;
        else if(alphabet.at(i) == 'J' || alphabet.at(i) == 'K' || alphabet.at(i) == 'L') sec+=6;
        else if(alphabet.at(i) == 'M' || alphabet.at(i) == 'N' || alphabet.at(i) == 'O') sec+=7;
        else if(alphabet.at(i) == 'P' || alphabet.at(i) == 'Q' || alphabet.at(i) == 'R' || alphabet.at(i) == 'S') sec+=8;
        else if(alphabet.at(i) == 'T' || alphabet.at(i) == 'U' || alphabet.at(i) == 'V') sec+=9;
        else if(alphabet.at(i) == 'W' || alphabet.at(i) == 'X' || alphabet.at(i) == 'Y' || alphabet.at(i) == 'Z') sec+=10;
    }
    cout << sec;
}