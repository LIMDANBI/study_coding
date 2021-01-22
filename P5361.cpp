#include <iostream>
using namespace std;

int main(){
    int t, a,b,c,d,e; double ans=0; cin>>t;
    for(int i=0; i<t; i++){
        cin>>a>>b>>c>>d>>e; ans+=(a*350.34+b*230.90+c*190.55+d*125.30+e*180.90); 
        cout << fixed; cout.precision(2); cout<<"$"<<ans<<'\n'; ans=0;
    }
}