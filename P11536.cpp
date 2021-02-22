#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, isincreasing=1, isdecreasing=1; cin>>n; string name[21], sorted[21];
    for(int i=0; i<n; i++) { cin>>name[i]; sorted[i]=name[i];}
    sort(sorted+0, sorted+n); 
    for(int i=0; i<n; i++){  if(name[i]!=sorted[i]) { isincreasing=0; break;}}
    if(isincreasing) cout<<"INCREASING";
    else{
        for(int i=0; i<n; i++){ if(name[i]!=sorted[n-1-i]) { isdecreasing=0; break;}}
        isdecreasing?cout<<"DECREASING":cout<<"NEITHER";
    }
}
