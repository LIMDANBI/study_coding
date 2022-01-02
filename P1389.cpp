#include <iostream>
using namespace std;

int arr[101][101]={};

int main(){
    int n, m; cin>>n>>m;
    int a, b, res=0, ans=1;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        arr[a][b]=1; arr[b][a]=1;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!arr[i][j] && arr[i][k] && arr[k][j] && i!=j)
                    arr[i][j] = arr[i][k] + arr[k][j];
                else if(arr[i][j] && arr[i][k] && arr[k][j] && i!=j)
                    arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        int tmp=0;
        for(int j=1; j<=n; j++) tmp+=arr[i][j];
        if(i==1) res=tmp;
        else if(tmp<res) {
            res=tmp;
            ans=i;
        }
    }
    cout<<ans;
}