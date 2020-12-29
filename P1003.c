# include <stdio.h>
int main(){
  int T=0, N=0; scanf("%d", &T);
  int zero[41]={1,0}; int one[41]={0,1};
  for(int i=2; i<41; i++){
    zero[i] = zero[i-2]+zero[i-1];
    one[i] = one[i-2]+one[i-1];
  }
  for (int i = 0; i<T; i++) {
    scanf("%d", &N);
    printf("%d %d", zero[N], one[N]); printf("\n");
  }
}

