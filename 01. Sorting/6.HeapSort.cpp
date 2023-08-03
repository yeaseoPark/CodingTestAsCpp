#include <stdio.h>
#include <algorithm>

const int number = 9;
int heap[number] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main(void){
	
	// 1. 최대힙구조 만들기 (상향식) 
	for(int i = 1; i < number; i ++){
		int c = i;
		do {
			int root = (c-1) / 2;
			if(heap[root] < heap[c]){
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			c = root;
		} while(c != 0);
	} 
	
	// 2. 크기를 줄여가며 반복적으로 힙을 구성 
	for(int i = number - 1; i >= 0; i --){
		// 2.1 최대값(루트값)과 맨 마지막에 있는 값을 교 환 
		int tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;
		
		// 2.2 다시 최대 힙 구성(하향식) 
		int root = 0, c = 1;
		do{
			c = 2 * root + 1;
			// 2.2.1 자식 중에 더 큰 값을 찾는다
			if(heap[c] < heap[c+1] && c < i-1){
				c++;
			}
			// 2.2.2 루트보다 자식이 더 크다면 교환
			if(heap[root] < heap[c] && c < i){
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			root = c;
		} while(c < i);
	} // for end
	
	// 3. 결과 출력 
	for(int i = 0; i < number; i ++) printf("%d ", heap[i]);
	
	return 0;
}
