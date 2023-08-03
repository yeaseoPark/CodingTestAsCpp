#include <stdio.h>

int array[1001];

int main(void){
	int number, i, j, min, min_idx, tmp;
	
	scanf("%d", &number);
	for(i = 0; i < number; i ++) scanf("%d", &array[i]);
	
	for(i = 0; i < number; i ++){
		min = 1001;
		min_idx = i;
		for(j = i ; j < number; j ++){
			if(min > array[j]){
				min = array[j];
				min_idx = j;
			}
		}
		
		tmp = array[i];
		array[i] = min;
		array[min_idx] = tmp;
	}
	
	for(i = 0; i < number; i ++) printf("%d\n", array[i]);
}
