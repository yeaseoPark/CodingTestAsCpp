#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	// yeaseo code
//	int tmp;
//	
//	
//	for(int i = 9; i >= 1; i --){
//		for(int j = 0; j < i; j ++){
//			if(arr[j] > arr[j+1]){
//				tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//			}
//		} // for end
//	} // for end

	// 예시코드
	int i, j, tmp;
	
	for(i = 0; i < 10; i ++){
		for(j = 0; j < 9 - i; j ++){
			if(arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		} // for end
	} // for end
	 
	
	for(int i = 0; i < 10; i ++) printf("%d, ", arr[i]);
}
