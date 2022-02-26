#include <stdio.h>

int main(){
    int namu[6] = {};
    scanf("%d %d %d %d %d", &namu[0], &namu[1], &namu[2], &namu[3], &namu[4]);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (namu[j] > namu[j + 1]){
                int tmp = namu[j];
                namu[j] = namu[j + 1];
                namu[j + 1] = tmp;
                printf("%d %d %d %d %d\n", namu[0], namu[1], namu[2], namu[3], namu[4]);
            }
        }
        if (namu[0] == 1 && namu[1] == 2 && namu[2] == 3 && namu[3] == 4 && namu[4] == 5)
            break;
    }
    return 0;
}