# include <iostream>
# include <cstdlib>
using namespace std;

int main(){
    int n, m, b; cin>>n>>m>>b;
    int h[n][m] = {};
    int num[257] = {};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>h[i][j];
            num[h[i][j]]++;
        }
    }
    int time=2100000000, height=0;
    for(int i=0; i<257; i++){
        int tmp=0, btmp=0;
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(i<h[j][k]) {
                    tmp+=(h[j][k]-i)*2;
                    btmp-=(h[j][k]-i);
                }
                else if(i>h[j][k]){
                    tmp+=(i-h[j][k]);
                    btmp+=(i-h[j][k]);
                }
            }
        }
        if(tmp<=time && btmp<=b){
            time = tmp;
            height = i;
        }
    }
    cout << time << ' ' << height;
}