# include <stdio.h>
int main(){
    int N, yon, sum=0; scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &yon); if(yon) sum++;
    }
    if(sum>N/2) printf("Junhee is cute!");
    else printf("Junhee is not cute!");
}