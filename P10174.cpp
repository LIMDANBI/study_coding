#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int n; cin>>n; string str; getline(cin, str);
    for(int i=0; i<n; i++){
        getline(cin, str); int idx1=0, idx2=str.size()-1, ispalindrome=1;
        while (idx1!=str.size()/2){
            if(str.at(idx1)!=str.at(idx2)){
                if((str.at(idx1)-str.at(idx2)==32 || str.at(idx1)-str.at(idx2)==-32));
                else {ispalindrome=0; break;}
            } idx1++; idx2--;
        } if(ispalindrome) cout<<"Yes"<<'\n'; else cout<<"No"<<'\n';
    }
}