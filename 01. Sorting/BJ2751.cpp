#include <stdio.h>

int data[1000000];
int sorted[1000000];
int number;

void merge(int data[], int start, int middle, int end){
	int s = start, e = middle + 1, t = start;
	
	while(s <= middle && e <= end){
		if(data[s] <= data[e]) sorted[t++] = data[s++];
		else sorted[t++] = data[e++];
	}
	
	while(s <= middle) sorted[t++] = data[s++];
	while(e <= end) sorted[t++] = data[e++];
	
	for(int k = start ; k <= end; k ++) data[k] = sorted[k];
}

void mergeSort(int data[], int m, int n){
	if(m >= n) return;
	int middle = (m + n) / 2;
	mergeSort(data, m, middle);
	mergeSort(data, middle + 1, n);
	merge(data, m, middle, n);
}

int main(void){
	scanf("%d", &number);
	for(int i = 0; i < number; i ++) scanf("%d", &data[i]);
	mergeSort(data, 0, number-1);
	for(int i = 0; i < number; i ++) printf("%d\n", data[i]);
	
	return 0;
}
