# include <stdio.h>
# include <algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d", &N);
	int arr[10001] = {};
	for(int i=0; i<N; i++){
		int tmp;
		scanf("%d", &tmp);
		arr[tmp]++;
	}
	for(int i=1; i<10001; i++){
		for(int j=0; j<arr[i]; j++){
			printf("%d\n", i);
		}
	}
}