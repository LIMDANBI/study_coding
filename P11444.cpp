#include<iostream>
#include<vector>
#define MOD 1000000007 
using namespace std;

typedef vector<vector<long long>> matrix;
long long n;

matrix operator *(matrix& a, matrix& b){ // 행렬 곱셈 
    matrix c(2, vector<long long>(2));
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++)
                c[i][j] += a[i][k]*b[k][j];
            c[i][j]%=MOD;
        }
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    matrix a = {{1, 1}, {1, 0}};
    matrix ans = {{1, 0}, {1, 0}};

    while (n>0){
        if(n&1) ans = ans*a;
        a=a*a;
        n>>=1;
    }
    cout << ans[0][1];
}