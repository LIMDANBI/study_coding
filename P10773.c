# include <stdio.h>
int main(){
    int stack[1000000]={0}; 
    int k, tmp, ans=0, idx=0, idx2=0; scanf("%d", &k);
    for(int i=0; i<k; i++){
        scanf("%d", &tmp);
        if(tmp == 0){
            idx--; stack[idx]=0;
        } //pop
        else{
            stack[idx]=tmp; idx++;
        } //push 
    }
    while(stack[idx2]!=0){
        ans+=stack[idx2]; idx2++;
    }
    printf("%d", ans);
}