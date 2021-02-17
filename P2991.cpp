#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a, b, c, d; cin>>a>>b>>c>>d; int delivery[3]; cin>>delivery[0]>>delivery[1]>>delivery[2]; int x=a+b, y=c+d;
    for(int i=0; i<3; i++){
        if(0<delivery[i]%x && delivery[i]%x<=a && 0<delivery[i]%y && delivery[i]%y<=c) cout<<2;
        else if(0<delivery[i]%x && delivery[i]%x<=a || 0<delivery[i]%y && delivery[i]%y<=c) cout<<1;
        else cout<<0; cout<<'\n';
    }
}