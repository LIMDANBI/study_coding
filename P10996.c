#include <stdio.h>
int main(){
    int N; scanf("%d", &N);
    if(N==1) printf("*");
    else{
        for(int i=1; i<=2*N; i++){
           for(int j=1; j<=N; j++){
                if(i%2==j%2) printf("*");
                else printf(" ");
            } printf("\n");
        }
    }
}