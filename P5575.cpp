#include<iostream>
using namespace std;
int main(){
    int h1, m1, s1, h2, m2, s2, h3, m3, s3;
    for(int i=0; i<3; i++){
        cin>>h1>>m1>>s1>>h2>>m2>>s2;
        if(s2<s1){ s3=s2+60-s1; m2--; } else s3=s2-s1;
        if(m2<m1){ m3=m2+60-m1; h2--; } else m3=m2-m1;
        h3=h2-h1; cout<<h3<<" "<<m3<<" "<<s3<<'\n';
    }
}