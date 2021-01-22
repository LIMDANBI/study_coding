#include <iostream>
using namespace std;

int main(){
    int n, m, element; cin>>n>>m; int matrix[n][m]{};
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){cin>>element; matrix[j][k]+=element;}
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout << matrix[i][j] << " "; cout<<'\n';
    }
}