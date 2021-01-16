#include <iostream>
using namespace std;

int main(){
    int a, b, ra, rb; cin >> a >> b;
    ra = a/100 + (a%100)/10*10 + (a%100)%10*100;
    rb = b/100 + (b%100)/10*10 + (b%100)%10*100;
    if(ra>rb) cout << ra;
    else cout << rb;
}