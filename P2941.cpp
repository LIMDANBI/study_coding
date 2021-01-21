#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string alphabet; cin >> alphabet; int ans=0, size=alphabet.size();
    for(int i=0; i<size; i++){
        if(alphabet.at(i)=='c'){
            if(i<size-1 && (alphabet.at(i+1)=='='||alphabet.at(i+1)=='-')) {ans++; i++;}
            else ans++;
        }
        else if(alphabet.at(i)=='l'){
            if(i<size-1 && alphabet.at(i+1)=='j') {ans++; i++;}
            else ans++;
        }
        else if(alphabet.at(i)=='n'){
            if(i<size-1 && alphabet.at(i+1)=='j') {ans++; i++;}
            else ans++;
        }
        else if(alphabet.at(i)=='s'){
            if(i<size-1 && (alphabet.at(i+1)=='='||alphabet.at(i+1)=='-')) {ans++; i++;}
            else ans++;
        }
        else if(alphabet.at(i)=='z'){
            if(i<size-1 && (alphabet.at(i+1)=='='||alphabet.at(i+1)=='-')) {ans++; i++;}
            else ans++;
        }
        else if(alphabet.at(i)=='d'){
            if(i<size-1 && alphabet.at(i+1)=='-') {ans++; i++;}
            else if(i<size-2 && alphabet.at(i+1)=='z' && alphabet.at(i+2)=='=') {ans++; i+=2;}
            else ans++;
        }
        else ans++;
    }
    cout << ans;
}