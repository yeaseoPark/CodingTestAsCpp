#include <stdio.h>

int main(void){
	const int size = 10;
	int arr[size] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	// 1. 流立 钱扁
//	int insert_idx, insert_val;
//	for(int i = 1; i < size; i ++){
//		insert_idx = i;
//		insert_val = arr[i];
//		
//		for(int j = 0; j < i; j ++){
//			if(arr[i] < arr[j]){
//				insert_idx = j;
//				insert_val = arr[i];
//				break;
//			}
//		} // for end;
//		
//		for(int j = i; j > insert_idx; j --){
//			arr[j] = arr[j-1];
//		}
//		arr[insert_idx] = insert_val;
//		
//	} // for end

	// 2. 抗力 内靛
	
	int i, j, tmp;
	
	for(i = 0; i < size-1; i ++) {
		j = i;
		while(arr[j] > arr[j+1]){
			tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
			j --;
		}
	}
	for(int i = 0; i < size; i ++) printf("%d, ", arr[i]);
	
	return 0;
}
