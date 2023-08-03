#include <stdio.h>
#include <algorithm>

const int number = 8;
int heap[number] = {1, 7, 5, 3, 9, 10, 2, 4};

void makeHeap(int * data, int end){
	int child, root;
	for(int c = end; c >= 1; c --){
		child = c;
		do{
			root = (child - 1) / 2;
			if(data[child] > data[root]){
				int tmp = data[child];
				data[child] = data[root];
				data[root] = tmp;
			}
			child = root;
		} while(child != 0);
	}
}

int main(void){
	// 1. 최초 최대 힙 구성
	makeHeap(heap, number - 1);
	
	// 2. 최대값(루트값)과 맨 마지막을 교환하는 것을 반복
	for(int i = number - 1; i > 0 ; i --){
		int tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;
		
		makeHeap(heap, i-1);
	}
	
	// 3. 출력
	for(int i = 0; i < number; i ++) printf("%d ", heap[i]); 
	return 0;
}
