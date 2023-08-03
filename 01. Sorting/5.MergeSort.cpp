#include <stdio.h>

int number = 8;
int sorted[8];

void merge(int * a, int m, int middle, int n){
	int i = m;
	int j = middle + 1;
	int k = m;
	
	while(i <= middle && j <= n){
		if(a[i] <= a[j]) sorted[k++] = a[i++];
		else sorted[k++] = a[j++];
	}
	
	while(i <= middle) sorted[k++] = a[i++];
	while(j <= n) sorted[k++] = a[j++];
	
	for(int t = m; t <= n; t++) a[t] = sorted[t];
}

void mergeSort(int a[], int m, int n){
	if(m >= n) return;
	int middle = (m + n) / 2;
	mergeSort(a, m, middle);
	mergeSort(a, middle + 1, n);
	merge(a, m, middle, n);
}


int main(void){
	int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
	mergeSort(array, 0, number - 1);
	for(int i = 0 ; i < number; i ++) printf("%d ", array[i]);
	return 0;
}
