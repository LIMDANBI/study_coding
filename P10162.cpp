#include <iostream>
using namespace std;

int main(){
    int T, A=0, B=0, C=0;
    cin >> T;
    if (T%10!=0) cout << -1;
    else{
        while (T>0){
            if (T >= 300){
                T-=300; A++;
            }
            else if (T >= 60){
                T-=60; B++;
            }
            else{
                T-=10; C++;
            }
        }
        cout <<A<<" "<<B<<" "<<C;
    }
}