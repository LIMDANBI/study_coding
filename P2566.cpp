# include <stdio.h>
int main(){
    int x=0, y=0;
    int max = -1;
    for(int i=0; i<9; i++){
        int arr[10] = {};
        for(int j=0; j<9; j++){
            scanf("%d", &arr[j]);
            if(max<arr[j]){
                x = i+1;
                y = j+1;
                max = arr[j];
            }
        }
    }
    printf("%d\n", max);
    printf("%d %d", x, y);
}