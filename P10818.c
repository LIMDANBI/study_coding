# include <stdio.h>
int main(){
    int max=-1000001, min=1000001;
    int N, tmp; scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &tmp);
        if(tmp<min) min=tmp;
        if(tmp>max) max=tmp;
    }
    printf("%d %d", min, max);
}