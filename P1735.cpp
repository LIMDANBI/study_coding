#include <iostream>
using namespace std;

int main(){
    int a1, b1, a2, b2; cin>>a1>>b1>>a2>>b2;
    int a=a1*b2+a2*b1, b=b1*b2;
    a1=a; b1=b;
    while (b1>0){
        int tmp = a1;
        a1 = b1;
        b1 = tmp%a1;
    }
    cout << a/a1 << ' ' << b/a1;
}