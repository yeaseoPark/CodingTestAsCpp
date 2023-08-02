#include <stdio.h>

const int size = 10;
int arr[size] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


void quickSort(int * data, int start, int end){
	if(start >= end) return;
	
	int left = start, right = end;
	int pivot = data[(start + end) / 2];
	int tmp;
	
	while(left <= right){
		while(data[left] < pivot) left ++;
		while(data[right] > pivot) right --;
		
		if(left <= right){
			tmp = data[left];
			data[left] = data[right];
			data[right] = tmp;
			
			left ++; right --;
		}
	}
	
	quickSort(data, start, right);
	quickSort(data, left, end);
}

void quickSort(int * data){
	quickSort(data, 0, size - 1);
}

int main(void){
	quickSort(arr);
	for(int i = 0; i < size; i ++) printf("%d ", arr[i]);
	
	return 0;
}
