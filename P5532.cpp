#include <iostream>
using namespace std;

int main(){
    int L, A, B, C, D, korea, math; cin>>L>>A>>B>>C>>D;
    A/C<A/(double)C?korea+=(A/C+1):korea+=(A/C);
    B/D<B/(double)D?math+=(B/D+1):math+=(B/D);
    if(math>korea) cout<<L-math;
    else cout<<L-korea;
}