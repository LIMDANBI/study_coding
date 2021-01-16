#include <iostream>
using namespace std;

int main(){
    int c; cin >> c;
    for(int i=0; i<c; i++){
        int n, avg, sum=0, morethan=0; cin >> n;
        int score[n]={};
        for(int j=0; j<n; j++){
            cin >> score[j]; sum+=score[j];
        }
        avg=sum/(double)n;
        for(int j=0; j<n; j++){
            if(avg<score[j]) morethan++;
        }
        cout << fixed;
        cout.precision(3);
        cout << morethan/(double)n*100 << "%" << endl;
    }
}