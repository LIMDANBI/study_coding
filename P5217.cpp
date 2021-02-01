#include<iostream>
using namespace std;
int main(){
    int t, n; cin>>t;
    while (t--){
        cin>>n;
        if(n<3) cout<<"Pairs for "<<n<<":"<<'\n';
        else{ cout<<"Pairs for "<<n<<": ";
            for(int i=1; i<=n/2; i++){
                if(i!=n-i) { 
                    cout<<i<<" "<<n-i;
                    if(n%2!=0 && i!=n/2) cout<<", ";
                    else if(n%2==0 && i!=n/2-1) cout<<", ";
                }
            }cout<<'\n';
        }
    }
}