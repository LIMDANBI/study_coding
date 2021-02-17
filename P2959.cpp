#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int step[4]; cin>>step[0]>>step[1]>>step[2]>>step[3]; sort(step+0, step+4);
    cout<<step[0]*step[2];
}