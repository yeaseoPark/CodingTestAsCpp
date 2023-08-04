#include <stdio.h>
#include <algorithm>

int temp;
int count[6];
int array[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
				 3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
				 3, 1, 4, 3, 5, 1, 2, 1, 1, 1};

int main(void){
	// 1. 배열 초기 화 
	for(int i = 0; i < 6; i ++){
		count[i] = 0;
	}
	
	// 2. array의 값과 일치하는 index 의 수를 1 씩 늘림(개수를 센다)
	for(int i = 0; i < 30; i ++){
		count[array[i]]++;
	}
	
	// 3. 정렬이 이루어진 결과를 출력
	for(int i = 0; i < 6; i ++){
		while(count[i] != 0) {
			printf("%d ", i);
			count[i] --;
		}
	} 
	return 0;
}
