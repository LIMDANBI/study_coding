#include <stdio.h>
int main(){
    int T, Y, K, sumY=0, sumK=0; scanf("%d", &T);
    for(int i=0; i<T; i++){
        for(int j=0; j<9; j++){
            scanf("%d %d", &Y, &K);
            sumK+=K; sumY+=Y;
        }
        if(sumY>sumK) printf("Yonsei\n");
        else if(sumY==sumK) printf("Draw\n");
        else printf("Korea\n");
        sumK=0; sumY=0;
    }
}