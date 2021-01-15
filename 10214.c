#include <stdio.h>
int main(){
    int T, Y, K, sumY=0, sumK=0; scanf("%d", &T);
    for(int i=0; i<T; i++){
        for(int j=0; j<9; j++){
            scanf("%d %d", &Y, &K);
            sumK+=K; sumY+=Y;
        }
        if(sumY>sumK) printf("Yonsei");
        else if(sumY==sumK) printf("Draw");
        else printf("Korea");
        sumK=0; sumY=0;
    }
}