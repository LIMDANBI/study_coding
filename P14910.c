#include<stdio.h>
int main(){
    int tmp, isincreasing=1, mx, isfirst=1;
    while (scanf("%d", &tmp)!=EOF){
        if(isfirst) { mx=tmp; isfirst=0;}
        else {
            if(tmp<mx) {isincreasing=0; break;}
            else mx=tmp;
        }
    } 
    if(isincreasing) printf("Good");
    else printf("Bad");
}