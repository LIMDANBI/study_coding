#include<iostream>
using namespace std;
int main(){
    int n, m, k; cin>>n>>m; int N[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>N[i][j];
    } cin>>m>>k; int M[m][k];
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++) cin>>M[i][j];
    } int A[n][k]{};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int l=0; l<k; l++) A[i][l]+=N[i][j]*M[j][l];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++) cout<<A[i][j]<<" "; cout<<'\n';
    }
}