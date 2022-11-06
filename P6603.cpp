#include <iostream>
#define SIX 6
#define MAX 15
using namespace std;

int k;
int num[MAX];
bool check[MAX];
int selected[SIX];

void combination(int cnt, int idx){
    if(cnt == SIX){
        for(int i=0; i<SIX; i++) cout << selected[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=idx; i<k; i++){
        if(check[i]) continue;
        check[i] = true;
        selected[cnt] = num[i];
        combination(cnt+1, i+1);
        check[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> k;
        if(k == 0) break;
        for(int i=0; i<k; i++) cin >> num[i];
        combination(0, 0);
        cout << "\n";
    }
}