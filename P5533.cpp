#include<iostream>
using namespace std;
int main(){
    int n; cin>>n; int score[201][4], player[201]{};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++) cin>>score[i][j];
    }
    for(int i=1; i<=3; i++){
        for(int j=1; j<=n; j++){
            int isin=0;
            for(int k=1; k<=n; k++){ if(j!=k&&score[j][i]==score[k][i]){isin=1; break;}}
            if(!isin) player[j]+=score[j][i];
        }
    } for(int i=1; i<=n; i++) cout<<player[i]<<'\n';
}