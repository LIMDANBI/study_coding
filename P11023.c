# include <stdio.h>
int main(){
    int num, ans=0;
    while(scanf("%d",&num)!=EOF) ans+=num;
    printf("%d", ans);
}