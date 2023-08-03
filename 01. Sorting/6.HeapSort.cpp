#include <stdio.h>
#include <algorithm>

const int number = 9;
int heap[number] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main(void){
	
	// 1. �ִ������� ����� (�����) 
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
	
	// 2. ũ�⸦ �ٿ����� �ݺ������� ���� ���� 
	for(int i = number - 1; i >= 0; i --){
		// 2.1 �ִ밪(��Ʈ��)�� �� �������� �ִ� ���� �� ȯ 
		int tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;
		
		// 2.2 �ٽ� �ִ� �� ����(�����) 
		int root = 0, c = 1;
		do{
			c = 2 * root + 1;
			// 2.2.1 �ڽ� �߿� �� ū ���� ã�´�
			if(heap[c] < heap[c+1] && c < i-1){
				c++;
			}
			// 2.2.2 ��Ʈ���� �ڽ��� �� ũ�ٸ� ��ȯ
			if(heap[root] < heap[c] && c < i){
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			root = c;
		} while(c < i);
	} // for end
	
	// 3. ��� ��� 
	for(int i = 0; i < number; i ++) printf("%d ", heap[i]);
	
	return 0;
}
