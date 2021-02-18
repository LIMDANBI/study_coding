#include<iostream>
using namespace std;
int main(){
    int t, num1, num2; cin>>t;
    while (t--) {
        string tmp1,tmp2="",sum; cin>>tmp1; int issymmetric=1;
        for(int i=0; i<tmp1.size(); i++) tmp2=tmp1[i]+tmp2;
        sum=to_string(stoi(tmp1)+stoi(tmp2));
        for(int i=0; i<(sum.size()-1)/2; i++){
            if(sum[i]!=sum[sum.size()-1-i]) issymmetric=0;
        } issymmetric?cout<<"YES":cout<<"NO"; cout<<'\n';
    }
}