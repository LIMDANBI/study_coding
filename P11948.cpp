#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int score1[4], score2[2], ans=0;
    for(int i=0; i<4; i++) cin>>score1[i]; cin>>score2[0]>>score2[1];
    sort(score1+0, score1+4); sort(score2+0, score2+2);
    for(int i=3; 0<i; i--) ans+=score1[i]; ans+=score2[1];
    cout<<ans;
}