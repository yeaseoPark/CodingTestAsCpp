#include <stdio.h>

const int MAX_VAL = 10000;

int N;
int C[MAX_VAL + 1];

int main(void){
	scanf("%d", &N);
	for(int i = 0; i < N; i ++) {
		int x;
		scanf("%d", &x);
		C[x] ++; 
	}
	
	for(int i = 0; i <= MAX_VAL; i ++) {
		while(C[i] != 0){
			printf("%d\n", i);
			C[i] --;
		}
	}
	
	return 0;
} 
