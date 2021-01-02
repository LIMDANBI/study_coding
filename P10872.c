# include <stdio.h>
int main(){
    int fac[13] = {}; fac[0]=1;
    for(int i=1; i<13; i++) fac[i] = fac[i-1]*i;
    int N; scanf("%d", &N);
    printf("%d", fac[N]);
}