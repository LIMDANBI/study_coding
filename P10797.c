# include <stdio.h>
int main(){
    int oneDigit, car, ans=0; scanf("%d", &oneDigit);
    for(int i=0; i<5; i++){
        scanf("%d", &car);
        if(oneDigit == car) ans++;
    }
    printf("%d", ans);
}