#include <stdio.h>
int main(){
    int T; scanf("%d", &T);
    int c, v, q=0, r=0;
    for(int i=0; i<T; i++){
        scanf("%d %d", &c, &v);
        q = c/v; r=c%v;
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", q, r);
    }
}